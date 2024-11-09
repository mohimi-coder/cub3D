/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:19:13 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:28:20 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	first_last_char(t_data *arg)
{
	int	i;
	int	j;

	i = 0;
	if (arg->map[i])
		i++;
	while (arg->map[i])
	{
		j = 1;
		if (arg->map[i][0] == '0' \
			||arg->map[i][ft_strlen(arg->map[i]) - 1] == '0')
			ft_error_message("Error:\nInvalid map!!");
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == '0' || arg->map[i][j] == 'W' \
	|| arg->map[i][j] == 'S' || arg->map[i][j] == 'E' || arg->map[i][j] == 'N')
			{
				if (arg->map[i][j - 1] == ' ' || arg->map[i][j + 1] == ' ' \
	|| arg->map[i - 1][j] == ' ' || arg->map[i + 1][j] == ' ')
					ft_error_message("Error:\nInvalid map!!");
			}
			j++;
		}
		i++;
	}
}

int	check_line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*check_last_line(char **file)
{
	int	i;

	i = 0;
	while (file[i] && !check_line_is_empty(file[i]))
		i++;
	if ((!file[i] && i != 0) \
		|| (file[i] && check_line_is_empty(file[i])))
		return (file[i - 1]);
	return (file[i]);
}

static void	check_empty_line_inside_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (check_line_is_empty(file[i]))
		{
			while (file[i] && check_line_is_empty(file[i]))
				i++;
			if (file[i])
				ft_error_message("Error:\nInvalid map!!");
		}
		if (file[i])
			i++;
	}
}

void	check_map(char **file, t_data *args)
{
	int	i;
	int	j;

	1 && (i = 0, j = 0);
	while (file[i] && check_line_is_empty(file[i]))
		i++;
	if (!file[i])
		ft_error_message("Error:\nInvalid map!!");
	check_empty_line_inside_map(file + i);
	check_first_line(file[i]);
	check_first_line(check_last_line(file + i));
	args->map = get_map_filled_with_spaces(file + i, args);
	first_last_char(args);
}
