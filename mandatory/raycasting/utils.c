/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:26:29 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/06 10:00:01 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

bool	is_wall(size_t x, int y, t_cube *cub)
{
	(void)cub;
	if (x < 0 || x > cub->data->width * TILE_SIZE || y < 0
		|| y > cub->data->height * TILE_SIZE)
		return (true);
	if (cub->data->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (true);
	return (false);
}

int	get_sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

bool	check_boundaries(double x, double y, t_cube *cube)
{
	if (!is_wall(x + 5, y + 5, cube) && !is_wall(x - 5, y + 5, cube)
		&& !is_wall(x + 5, y - 5, cube) && !is_wall(x - 5, y - 5, cube))
		return (true);
	return (false);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	calculate_closest_ray(t_inter ch, t_inter cv, t_cube *cube)
{
	double	h_dis;
	double	v_dis;

	h_dis = sqrt(pow(cube->player->x - ch.x, 2)
			+ pow(cube->player->y - ch.y, 2));
	v_dis = sqrt(pow(cube->player->x - cv.x, 2)
			+ pow(cube->player->y - cv.y, 2));
	if (h_dis <= v_dis)
	{
		cube->hit->dist = h_dis;
		cube->hit->x = ch.x;
		cube->hit->y = ch.y;
		cube->hit->ver_hit = 0;
		return ;
	}
	cube->hit->dist = v_dis;
	cube->hit->x = cv.x;
	cube->hit->y = cv.y;
	cube->hit->ver_hit = 1;
}
