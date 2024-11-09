/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:17:24 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/06 09:59:16 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	open_door(t_cube *cube)
{
	int		j;
	size_t	i;
	double	dist_x;
	double	dist_y;
	double	dist;

	j = 0;
	while (j < cube->data->height)
	{
		i = 0;
		while (i < cube->data->width)
		{
			if (cube->data->map[j][i] == 'D')
			{
				dist_x = i * TILE_SIZE + TILE_SIZE / 2 - cube->player->x;
				dist_y = j * TILE_SIZE + TILE_SIZE / 2 - cube->player->y;
				dist = sqrt(dist_x * dist_x + dist_y * dist_y);
				if (dist < TILE_SIZE * 3)
					cube->data->map[j][i] = 'd';
			}
			i++;
		}
		j++;
	}
}

void	ft_close_door(t_cube *cube)
{
	int		j;
	size_t	i;
	double	dist_x;
	double	dist_y;
	double	dist;

	j = 0;
	while (j < cube->data->height)
	{
		i = 0;
		while (i < cube->data->width)
		{
			if (cube->data->map[j][i] == 'd')
			{
				dist_x = i * TILE_SIZE + TILE_SIZE / 2 - cube->player->x;
				dist_y = j * TILE_SIZE + TILE_SIZE / 2 - cube->player->y;
				dist = sqrt(dist_x * dist_x + dist_y * dist_y);
				if (dist > TILE_SIZE * 4)
					cube->data->map[j][i] = 'D';
			}
			i++;
		}
		j++;
	}
}

mlx_texture_t	*my_mlx_load_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error_message("Error:\ntexture encountered");
	return (texture);
}

mlx_image_t	*my_mlx_texture_to_image(void *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		ft_error_message("Error:\ntexture encountered");
	mlx_delete_texture(texture);
	return (image);
}

void	ft_close(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clear_spr(cube);
	clearheap(&cube->heap);
	mlx_close_window(cube->mlx);
	exit(0);
}
