/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:38 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:15:02 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

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
			valid_element(arg, i, j);
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
