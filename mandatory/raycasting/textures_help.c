/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:43:23 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/06 09:59:59 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

uint32_t	get_texture_pixel(mlx_image_t *texture, int x, int y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if (!texture)
		return (0x000000);
	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * 4;
		r = texture->pixels[index];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000);
}

mlx_image_t	*find_texture(t_cube *cube)
{
	mlx_image_t	*txt;

	if (!cube->hit->ver_hit)
	{
		if (cube->ray->is_up)
			txt = cube->data->no_image_texture;
		else
			txt = cube->data->so_image_texture;
	}
	else
	{
		if (cube->ray->is_right)
			txt = cube->data->we_image_texture;
		else
			txt = cube->data->ea_image_texture;
	}
	return (txt);
}

void	calculate_tex_pos(t_cube *cube, mlx_image_t *tex, double w_h, int f_y)
{
	if (w_h > 0)
		cube->data->step = (double)tex->height / w_h;
	else
		cube->data->step = 0;
	cube->data->text_pos = (f_y - (SCREEN_HEIGHT / 2 - w_h / 2)) \
		* cube->data->step;
}

void	sel_calculate_texture(t_cube *cube, mlx_image_t *current_tex)
{
	if (!cube->hit->ver_hit)
		cube->data->text_x = (int)(cube->hit->x * current_tex->width \
			/ TILE_SIZE) % current_tex->width;
	else
		cube->data->text_x = (int)(cube->hit->y * \
		current_tex->width / TILE_SIZE) % current_tex->width;
}

void	load_textures(t_cube *cube)
{
	cube->data->no_texture = my_mlx_load_png(cube->data->no);
	cube->data->so_texture = my_mlx_load_png(cube->data->so);
	cube->data->we_texture = my_mlx_load_png(cube->data->we);
	cube->data->ea_texture = my_mlx_load_png(cube->data->ea);
	ft_texture_to_image(cube);
}
