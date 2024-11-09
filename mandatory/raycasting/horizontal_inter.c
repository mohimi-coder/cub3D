/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:44:46 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/06 09:59:45 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_inter	calculate_first_horizontal_touch(t_cube *cube, double angle)
{
	t_inter	first_touch;

	first_touch.y = floor(cube->player->y / TILE_SIZE) * TILE_SIZE;
	if (angle > 0 && angle < M_PI)
		first_touch.y += TILE_SIZE;
	first_touch.x = cube->player->x
		+ (first_touch.y - cube->player->y) / tan(angle);
	if (first_touch.x > cube->data->width * TILE_SIZE)
		first_touch.x = cube->data->width * TILE_SIZE - 1;
	return (first_touch);
}

t_inter	calculate_next_horizontal_step(double angle)
{
	t_inter	next_step;

	next_step.y = TILE_SIZE;
	if (!(angle > 0 && angle < M_PI))
		next_step.y *= -1;
	next_step.x = TILE_SIZE / tan(angle);
	if ((next_step.x > 0 && angle < M_PI * 1.5 && angle > M_PI / 2)
		|| (next_step.x < 0 && !(angle < M_PI * 1.5 && angle > M_PI / 2)))
		next_step.x *= -1;
	return (next_step);
}

t_inter	wall_hor(t_cube *cube, t_inter f_touch, t_inter next_step, double angle)
{
	t_inter	check;
	int		t;

	check = f_touch;
	while (!(check.x < 0 || check.x > cube->data->width * TILE_SIZE
			|| check.y < 0 || check.y > cube->data->height * TILE_SIZE))
	{
		t = check.y;
		if (angle >= M_PI && angle <= 2 * M_PI)
			t = check.y - 1;
		if (is_wall(check.x, t, cube))
			break ;
		check.x += next_step.x;
		check.y += next_step.y;
	}
	return (check);
}

t_inter	find_horizontal_intersection(t_cube *cube, double angle)
{
	t_inter	first_touch;
	t_inter	next_step;

	first_touch = calculate_first_horizontal_touch(cube, angle);
	next_step = calculate_next_horizontal_step(angle);
	return (wall_hor(cube, first_touch, next_step, angle));
}

void	put_pixel_safe(mlx_image_t *img, long x, long y, long color)
{
	if ((x < 0 || x >= SCREEN_WIDTH) || (y < 0 || y >= SCREEN_HEIGHT))
		return ;
	mlx_put_pixel(img, x, y, color);
}
