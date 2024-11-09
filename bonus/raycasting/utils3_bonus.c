/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:12:49 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/08 20:08:40 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	ft_door_texture(t_cube *cube)
{
	cube->data->door_text = my_mlx_load_png("door/1.png");
	cube->data->door_image_text = my_mlx_texture_to_image \
		(cube->mlx, cube->data->door_text);
}

void	ft_east_west(t_cube *cube, double x)
{
	if (x > 0)
	{
		if (cube->data->map[(int)cube->hit->y \
			/ TILE_SIZE][(int)cube->hit->x / TILE_SIZE] == 'D')
			cube->data->found_doorl = true;
	}
	else
	{
		if (cube->data->map[(int)cube->hit->y \
			/ TILE_SIZE][(int)cube->hit->x / TILE_SIZE - 1] == 'D')
			cube->data->found_doorl = true;
	}
}

void	normalize_door(t_cube *cube)
{
	double	x;
	double	y;

	x = cube->hit->x - cube->player->x;
	y = cube->hit->y - cube->player->y;
	if (cube->hit->ver_hit == 1)
		ft_east_west(cube, x);
	else
	{
		if (y > 0)
		{
			if (cube->data->map[(int)cube->hit->y \
				/ TILE_SIZE][(int)cube->hit->x / TILE_SIZE] == 'D')
				cube->data->found_doorl = true;
		}
		else
		{
			if (cube->data->map[(int)cube->hit->y \
				/ TILE_SIZE - 1][(int)cube->hit->x / TILE_SIZE] == 'D')
				cube->data->found_doorl = true;
		}
	}
}

void	clear_spr(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->data && i < 100)
	{
		free(cube->data->s_sprite[i]->pixels);
		free(cube->data->s_sprite[i]);
		i++;
	}
	exit(0);
}
