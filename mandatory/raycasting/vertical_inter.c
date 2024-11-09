/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:51:23 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/06 10:00:19 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_inter	calculate_first_touch(t_cube *cube, double angle)
{
	t_inter	first_touch;

	first_touch.x = floor(cube->player->x / TILE_SIZE) * TILE_SIZE;
	if (angle > M_PI * 1.5 || angle < M_PI / 2)
		first_touch.x += TILE_SIZE;
	first_touch.y = cube->player->y + (first_touch.x - cube->player->x)
		* tan(angle);
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
