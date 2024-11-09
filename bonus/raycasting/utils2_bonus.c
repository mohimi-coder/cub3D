/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:29 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/06 09:59:10 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

char	*ft_itoa(int n)
{
	char	arr[12];
	long	b;
	int		i;
	int		divisor;

	b = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (b < 0)
		b *= -1;
	divisor = 1000000000;
	arr[0] = '0';
	i = 0;
	while (++i <= 10)
	{
		arr[i] = b / divisor + '0';
		b %= divisor;
		divisor /= 10;
	}
	i = 0;
	while (arr[i] == '0')
		i++;
	if (n < 0)
		arr[--i] = '-';
	return (arr[11] = '\0', ft_strdup(&arr[i]));
}

void	load_sprite_textures(t_cube *cube)
{
	char	*str;
	char	*tmp2;
	int		i;

	i = 0;
	while (i < 100)
	{
		str = NULL;
		str = ft_strjoin(str, "knife/");
		tmp2 = ft_itoa(i + 1);
		str = ft_strjoin(str, tmp2);
		str = ft_strjoin(str, ".png");
		cube->data->s_sprite[i] = mlx_load_png(str);
		if (!cube->data->s_sprite[i])
			ft_error_message("Error:\nsprite texture encountered");
		i++;
	}
}

void	ft_animation(t_cube *cub)
{
	static int	i;

	if (i % 2 == 0)
	{
		mlx_delete_image(cub->mlx, cub->data->tp);
		cub->data->tp = mlx_texture_to_image(cub->mlx, \
			cub->data->s_sprite[cub->data->fram]);
		mlx_image_to_window(cub->mlx, cub->data->tp, 0, 0);
		if (!cub->data->animt)
			cub->data->fram = 0;
		if (cub->data->animt && cub->data->fram == 99)
		{
			cub->data->fram = 0;
			cub->data->animt = 0;
		}
		cub->data->fram++;
	}
	i++;
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
