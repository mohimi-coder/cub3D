/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:05:27 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/09 20:53:08 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	apply_shadow(uint32_t *color, t_cube *cube, double max_distance)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	double		intensity;

	intensity = 1 - (cube->ray->dis / max_distance);
	if (intensity < 0.3)
		intensity = 0.3;
	r = (*color >> 24) & 0xFF;
	g = (*color >> 16) & 0xFF;
	b = (*color >> 8) & 0xFF;
	r *= intensity;
	g *= intensity;
	b *= intensity;
	*color = (r << 24) | (g << 16) | (b << 8) | 0xff;
}

void	cal_wall_dimen(t_cube *cube, int *from_y, int *to_y, double *w_height)
{
	double	base_distance;

	base_distance = (SCREEN_WIDTH / 2) / tan(cube->fov_angle / 2);
	*w_height = (TILE_SIZE / cube->ray->dis) * base_distance;
	*from_y = (SCREEN_HEIGHT / 2) - (*w_height / 2);
	*to_y = *from_y + *w_height;
	if (*from_y < 0)
		*from_y = 0;
	if (*to_y > SCREEN_HEIGHT)
		*to_y = SCREEN_HEIGHT;
}

int	mlx_data_init(t_cube *cube)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	cube->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", true);
	if (!cube->mlx)
	{
		mlx_strerror(mlx_errno);
		return (1);
	}
	cube->image = mlx_new_image(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cube->image)
	{
		clearheap(&cube->heap);
		mlx_close_window(cube->mlx);
		mlx_strerror(mlx_errno);
		return (1);
	}
	if (mlx_image_to_window(cube->mlx, cube->image, 0, 0) == -1)
	{
		clearheap(&cube->heap);
		mlx_close_window(cube->mlx);
		mlx_strerror(mlx_errno);
		return (1);
	}
	return (0);
}

int	data_init(t_cube *cube, t_player *player, t_inter *hit, t_ray *ray)
{
	cube->hit = hit;
	cube->ray = ray;
	cube->player = player;
	cube->player->angle = update_angle(cube);
	cube->fov_angle = 60 * (M_PI / 180);
	cube->cursor_hidden = 0;
	if (mlx_data_init(cube))
		return (1);
	return (0);
}
