/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:53 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:13:56 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	is_num(char *str)
{
	while (*str)
	{
		if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
			ft_error_message("Error:\nInvalid color!!");
		str++;
	}
}

void	init_data(t_data *args)
{
	args->f_c = -1;
	args->c_color = -1;
	args->no = NULL;
	args->so = NULL;
	args->we = NULL;
	args->ea = NULL;
	args->map = NULL;
	args->height = 0;
	args->width = 0;
}

void	check_params(t_data args)
{
	if (!args.no || !args.so || !args.we || !args.ea)
		ft_error_message("Error:\nMissing texture!!");
	if (args.f_c == -1 || args.c_color == -1)
		ft_error_message("Error:\nMissing color!!");
}

static void	check_valid_map(t_data *args)
{
	int	i;
	int	j;

	1 && (i = 0, j = 0);
	while (args->map[i])
	{
		j = 0;
		while (args->map[i][j])
		{
			if (args->map[i][j] != '1' && args->map[i][j] != '0' \
				&& args->map[i][j] != 'N' \
				&& args->map[i][j] != 'S' && args->map[i][j] != 'W' \
				&& args->map[i][j] != 'E' && args->map[i][j] != ' ' \
				&& args->map[i][j] != 'D')
				ft_error_message("Error:\nInvalid map!!");
			j++;
		}
		i++;
	}
}

void	check_elements(t_data *args)
{
	int	i;
	int	j;
	int	count;

	1 && (i = 0, count = 0, j = 0);
	while (args->map[i])
	{
		j = 0;
		while (args->map[i][j])
		{
			if (args->map[i][j] == 'N' || args->map[i][j] == 'S' \
				|| args->map[i][j] == 'W' || args->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_error_message("Error:\nInvalid number of players!!");
	check_valid_map(args);
}
