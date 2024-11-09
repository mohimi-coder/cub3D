/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:32:36 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/08 19:57:38 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	initialize_position(t_data *data, double *x, double *y)
{
	int		j;
	size_t	i;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
			|| data->map[j][i] == 'W' || data->map[j][i] == 'E')
			{
				*x = i * TILE_SIZE + TILE_SIZE / 2;
				*y = j * TILE_SIZE + TILE_SIZE / 2;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	draw_player(void *param)
{
	t_cube	*cube;
	int		x;
	int		y;

	cube = param;
	y = -2;
	while (y <= 2)
	{
		x = -2;
		while (x <= 2)
		{
			put_pixel_safe(cube->image, 100 + x,
				100 + y, 0xD1C7D7D1);
			x++;
		}
		y++;
	}
}

void	handle_key_release(mlx_key_data_t keydata, t_cube *cube)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == 320)
			cube->cursor_hidden = 1;
		else if (keydata.key == 321)
			cube->cursor_hidden = 0;
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
			cube->player->wd = 0;
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			cube->player->ard = 0;
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
			cube->player->td = 0;
	}
}

void	handle_key_input(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (clear_spr(cube), clearheap(&cube->heap),
			mlx_close_window(cube->mlx));
	else if (keydata.key == MLX_KEY_W)
		cube->player->wd = 1;
	else if (keydata.key == MLX_KEY_S)
		cube->player->wd = -1;
	else if (keydata.key == MLX_KEY_A)
		cube->player->ard = -1;
	else if (keydata.key == MLX_KEY_D)
		cube->player->ard = 1;
	else if (keydata.key == MLX_KEY_RIGHT)
		cube->player->td = 1;
	else if (keydata.key == MLX_KEY_LEFT)
		cube->player->td = -1;
	if (keydata.key == MLX_KEY_R)
		1 && ((!cube->data->animt) && (cube->data->fram = 0),
			cube->data->animt = 1);
	if (keydata.key == MLX_KEY_O)
		open_door(cube);
	handle_key_release(keydata, cube);
}

void	move_player(t_cube *cube)
{
	int	nextpos[2];

	cube->player->angle += 0.06 * cube->player->td;
	nextpos[0] = cos(cube->player->angle) * SPEED * cube->player->wd;
	nextpos[1] = sin(cube->player->angle) * SPEED * cube->player->wd;
	if (check_boundaries(cube->player->x + nextpos[0],
			cube->player->y + nextpos[1], cube))
	{
		cube->player->x += nextpos[0];
		cube->player->y += nextpos[1];
	}
	nextpos[0] = cos(cube->player->angle + M_PI / 2) \
		* SPEED * cube->player->ard;
	nextpos[1] = sin(cube->player->angle + M_PI / 2) \
		* SPEED * cube->player->ard;
	if (check_boundaries(cube->player->x + nextpos[0],
			cube->player->y + nextpos[1], cube))
	{
		cube->player->x += nextpos[0];
		cube->player->y += nextpos[1];
	}
}
