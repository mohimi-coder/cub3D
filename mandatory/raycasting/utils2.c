/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:37:23 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/06 10:00:08 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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
		ft_error_message("Error:\nimage encountered");
	mlx_delete_texture(texture);
	return (image);
}

void	ft_texture_to_image(t_cube *cube)
{
	cube->data->no_image_texture = my_mlx_texture_to_image \
		(cube->mlx, cube->data->no_texture);
	cube->data->so_image_texture = my_mlx_texture_to_image \
		(cube->mlx, cube->data->so_texture);
	cube->data->we_image_texture = my_mlx_texture_to_image \
		(cube->mlx, cube->data->we_texture);
	cube->data->ea_image_texture = my_mlx_texture_to_image \
		(cube->mlx, cube->data->ea_texture);
}

void	ft_clear_image(mlx_image_t *img)
{
	uint32_t		i;
	uint32_t		j;
	unsigned int	clear;

	i = 0;
	clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			put_pixel_safe(img, j, i, clear);
			j++;
		}
		i++;
	}
}

void	ft_close(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clearheap(&cube->heap);
	mlx_close_window(cube->mlx);
	exit(0);
}
