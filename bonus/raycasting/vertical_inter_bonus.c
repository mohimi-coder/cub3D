/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:46 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/08 19:58:34 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

t_inter	calculate_first_touch(t_cube *cube, double angle)
{
	t_inter	first_touch;

	first_touch.x = floor(cube->player->x / TILE_SIZE) * TILE_SIZE;
	if (angle > M_PI * 1.5 || angle < M_PI / 2)
		first_touch.x += TILE_SIZE;
	first_touch.y = cube->player->y + (first_touch.x - cube->player->x) \
		* tan(angle);
	if (first_touch.y > cube->data->height * TILE_SIZE)
		first_touch.y = cube->data->height * TILE_SIZE - 1;
	return (first_touch);
}

t_inter	calculate_next_step(double angle)
{
	t_inter	next_step;

	next_step.x = TILE_SIZE;
	if (angle < M_PI * 1.5 && angle > M_PI / 2)
		next_step.x *= -1;
	next_step.y = TILE_SIZE * tan(angle);
	if ((next_step.y > 0 && !(angle > 0 && angle < M_PI)) || (next_step.y < 0
			&& angle > 0 && angle < M_PI))
		next_step.y *= -1;
	return (next_step);
}

t_inter	wall_ver(t_cube *cube, t_inter f_touch, t_inter next_step, double angle)
{
	t_inter	check;
	size_t	t;

	check = f_touch;
	while (!(check.x < 0 || check.x > cube->data->width * TILE_SIZE
			|| check.y < 0 || check.y > cube->data->height * TILE_SIZE))
	{
		t = check.x;
		if (angle >= M_PI * 0.5 && angle <= M_PI * 1.5)
			t = check.x - 1;
		if (is_wall(t, check.y, cube))
			break ;
		check.x += next_step.x;
		check.y += next_step.y;
	}
	return (check);
}

t_inter	find_vertical_intersection(t_cube *cube, double angle)
{
	t_inter	first_touch;
	t_inter	next_step;

	first_touch = calculate_first_touch(cube, angle);
	next_step = calculate_next_step(angle);
	return (wall_ver(cube, first_touch, next_step, angle));
}

void	bresenham_line_mini(t_line_y line_x, t_line_y line_y, t_cube *cub)
{
	long	dif[2];
	long	step[2];
	long	err[2];
	long	pos[2];

	dif[0] = labs(line_x.to - line_x.from);
	dif[1] = labs(line_y.to - line_y.from);
	step[0] = get_sign(line_x.from, line_x.to);
	1 && (step[1] = get_sign(line_y.from, line_y.to), err[0] = dif[0] - dif[1]);
	1 && (pos[0] = line_x.from, pos[1] = line_y.from);
	while (pos[0] != line_x.to || pos[1] != line_y.to)
	{
		put_pixel_mini(cub->image, pos[0], pos[1], 0xC9E2BFE2);
		err[1] = 2 * err[0];
		if (err[1] > -dif[1])
		{
			err[0] -= dif[1];
			pos[0] += step[0];
		}
		if (err[1] < dif[0])
		{
			err[0] += dif[0];
			pos[1] += step[1];
		}
	}
}
