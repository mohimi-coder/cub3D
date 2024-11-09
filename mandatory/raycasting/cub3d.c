/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:08:10 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/06 09:59:40 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	function(void *param)
{
	t_cube	*cube;

	cube = (t_cube *) param;
	ft_clear_image(cube->image);
	move_player(cube);
	render_3d(cube);
}

int	main(int ac, char **av)
{
	t_cube		cube;
	t_player	player;
	t_inter		hit;
	t_ray		ray[SCREEN_WIDTH];

	if (ac != 2)
		ft_error_message("num of args isn't correct.Usage: ./cub3D <map_file>");
	get_cub(&cube);
	cube.data = ft_parsing(av);
	if (data_init(&cube, &player, &hit, ray))
		return (1);
	load_textures(&cube);
	initialize_position(cube.data, &cube.player->x, &cube.player->y);
	mlx_loop_hook(cube.mlx, function, &cube);
	mlx_key_hook(cube.mlx, handle_key_input, &cube);
	mlx_close_hook(cube.mlx, ft_close, &cube);
	mlx_loop(cube.mlx);
}
