/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpe3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:24 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:16:06 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

static int	create_trgb(int t, int r, int g, int b)
{
	int	color;

	color = ((r << 24) | (g << 16) | (b << 8) | t);
	return (color);
}

void	assign_color(t_data *args, char *line, char **tmp2)
{
	if (args->f_c == -1 && !ft_strncmp(line, "F", 1))
	{
		args->f_c = create_trgb(254, ft_atoi(tmp2[0]), \
		ft_atoi(tmp2[1]), ft_atoi(tmp2[2]));
	}
	else if (args->c_color == -1 && !ft_strncmp(line, "C", 1))
	{
		args->c_color = create_trgb(254, ft_atoi(tmp2[0]), \
		ft_atoi(tmp2[1]), ft_atoi(tmp2[2]));
	}
	else
		ft_error_message("Error:\nduplicate color!!");
}

void	check_map_round_byones(t_data *args)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	while (args->map[++i])
	{
		j = 0;
		while (args->map[i][j] == ' ')
			j++;
		len = (int)ft_strlen(args->map[i]) - 1;
		while (len >= 0 && args->map[i][len] == ' ')
			len--;
		if (args->map[i][j] != '1' || args->map[i][len] != '1')
			ft_error_message("Error:\nmap is not closed by '1'!!");
	}
}
