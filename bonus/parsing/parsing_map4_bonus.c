/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map4_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:02:15 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:22:46 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	check_valid_doors(t_data *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'D')
			{
				if ((arg->map[i][j - 1] != '1' || arg->map[i][j + 1] != '1') \
					&& (arg->map[i - 1][j] != '1' || arg->map[i + 1][j] != '1'))
					ft_error_message("Error:\nInvalid door!!");
				else if ((arg->map[i][j - 1] == '1'
					&& arg->map[i][j + 1] == '1')
					&& (arg->map[i - 1][j] == '1' && arg->map[i + 1][j] == '1'))
					ft_error_message("Error:\nInvalid door!!");
			}
			j++;
		}
		i++;
	}
}

void	valid_element(t_data *arg, int i, int j)
{
	check_valid_doors(arg);
	if (arg->map[i][j] == '0' || arg->map[i][j] == 'W' \
		|| arg->map[i][j] == 'S' || arg->map[i][j] == 'E' \
		|| arg->map[i][j] == 'N' || arg->map[i][j] == 'D')
	{
		if (arg->map[i][j - 1] == ' ' || arg->map[i][j + 1] == ' ' \
			|| arg->map[i - 1][j] == ' ' || arg->map[i + 1][j] == ' ')
			ft_error_message("Error:\nInvalid map!!");
	}
}
