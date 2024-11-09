/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:23:21 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/09 20:53:38 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_init_der(double *ray, t_cube *cube)
{
	cube->ray->is_down = *ray > 0 && *ray < M_PI;
	cube->ray->is_up = !cube->ray->is_down;
	cube->ray->is_right = *ray < M_PI / 2 || *ray > (3 * M_PI) / 2;
	cube->ray->is_left = !cube->ray->is_right;
}

void	render_3d(void *param)
{
	t_inter	ch;
	t_inter	cv;
	t_cube	*cube;
	double	ray;
	int		x;

	x = -1;
	cube = (t_cube *)param;
	ray = cube->player->angle - (cube->fov_angle / 2);
	while (++x < SCREEN_WIDTH)
	{
		ray = normalize_angle(ray);
		ft_init_der(&ray, cube);
		cv = find_vertical_intersection(cube, ray);
		ch = find_horizontal_intersection(cube, ray);
		calculate_closest_ray(ch, cv, cube);
		render_wall(cube, x, ray);
		ray += cube->fov_angle / SCREEN_WIDTH;
	}
}

void	draw_text(t_line_y line_y, mlx_image_t *cur_tex, t_cube *cube, long x)
{
	cube->ray->i = line_y.from;
	while (cube->ray->i < line_y.to)
	{
		cube->data->text_y = (int)cube->data->text_pos % cur_tex->height;
		cube->ray->color = get_texture_pixel(cur_tex, \
		cube->data->text_x, cube->data->text_y);
		apply_shadow(&cube->ray->color, cube, 700);
		put_pixel_safe(cube->image, x, cube->ray->i, cube->ray->color);
		cube->data->text_pos += cube->data->step;
		cube->ray->i++;
	}
}

void	render_wall(t_cube *cube, double x, double ray)
{
	double		wall_height;
	int			from_y;
	int			to_y;
	t_line_y	line_y;
	mlx_image_t	*cur_tex;

	cube->ray->dis = cube->hit->dist * cos(cube->player->angle - ray);
	cal_wall_dimen(cube, &from_y, &to_y, &wall_height);
	cur_tex = find_texture(cube);
	if (!cur_tex)
		ft_error_message("Error:\nTexture not found!!");
	sel_calculate_texture(cube, cur_tex);
	calculate_tex_pos(cube, cur_tex, wall_height, from_y);
	line_y.to = to_y;
	line_y.from = from_y;
	draw_text(line_y, cur_tex, cube, x);
	line_y.to = 0;
	line_y.from = from_y;
	bresenham_line(x, line_y, cube, cube->data->c_color);
	line_y.to = to_y - 1;
	line_y.from = SCREEN_HEIGHT;
	bresenham_line(x, line_y, cube, cube->data->f_c);
}

void	bresenham_line(long x, t_line_y line_y, t_cube *cub, long color)
{
	long	diff[2];
	long	step[2];
	long	error[2];
	long	pos[2];

	1 && (diff[0] = labs(x - x), step[0] = get_sign(x, x));
	diff[1] = labs(line_y.to - line_y.from);
	step[1] = get_sign(line_y.from, line_y.to);
	error[0] = diff[0] - diff[1];
	1 && (pos[0] = x, pos[1] = line_y.from);
	while (pos[0] != x || pos[1] != line_y.to)
	{
		put_pixel_safe(cub->image, pos[0], pos[1], color);
		error[1] = 2 * error[0];
		if (error[1] > -diff[1])
		{
			error[0] -= diff[1];
			pos[0] += step[0];
		}
		if (error[1] < diff[0])
		{
			error[0] += diff[0];
			pos[1] += step[1];
		}
	}
}
