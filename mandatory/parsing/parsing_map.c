/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:32:30 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/09 11:33:47 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_count_comma(char *line)
{
	int	i;
	int	count;

	1 && (i = 0, count = 0);
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error_message("Error:\nInvalid color!!");
}

void	process_texture(char **texture, char *file, char *prefix)
{
	char	*tmp;
	char	*line;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(file) - ft_strlen(prefix);
	tmp = ft_substr(file, ft_strlen(prefix), len);
	while (tmp[i])
	{
		if (tmp[i] == '\t')
			ft_error_message("Error:\nInvalid texture!!");
		i++;
	}
	line = ft_strtrim(tmp, " ");
	*texture = ft_strdup(line);
}

void	get_textures(t_data *args, char **file, int *i)
{
	if (!args->no && !ft_strncmp(file[*i], "NO", 2))
		process_texture(&args->no, file[*i], "NO");
	else if (!args->so && !ft_strncmp(file[*i], "SO", 2))
		process_texture(&args->so, file[*i], "SO");
	else if (!args->we && !ft_strncmp(file[*i], "WE", 2))
		process_texture(&args->we, file[*i], "WE");
	else if (!args->ea && !ft_strncmp(file[*i], "EA", 2))
		process_texture(&args->ea, file[*i], "EA");
	else
		ft_error_message("Error:\nduplicate texture!!");
}

void	get_color(t_data *args, char **file, int *i)
{
	char	**tmp2;
	int		k;
	char	*line;
	int		a;

	1 && (tmp2 = NULL, k = 0, a = 0);
	line = ft_strtrim(file[*i], " ");
	if (line[0] == 'F' || line[0] == 'C')
		k++;
	while (line[k] && line[k] == ' ')
		k++;
	ft_count_comma(line + k);
	tmp2 = ft_split(line + k, ',');
	if (!tmp2)
		ft_error_message("Error:\nfrom split!!");
	while (tmp2[a])
		is_num(tmp2[a++]);
	if (a != 3)
		ft_error_message("Error:\nInvalid color!!");
	assign_color(args, line, tmp2);
}

void	get_data(t_data *args, char **file, int *r)
{
	int		i;
	int		count;
	char	*tmp;

	1 && (i = 0, count = 0);
	while (file[i])
	{
		tmp = file[i];
		if (!ft_strncmp(file[i], "NO ", 3) || !ft_strncmp(file[i], "SO ", 3) \
			|| !ft_strncmp(file[i], "WE ", 3) || !ft_strncmp(file[i], "EA ", 3))
			(get_textures(args, file, &i), count++);
		else if (!ft_strncmp(file[i], "F ", 2) || \
			!ft_strncmp(file[i], "C ", 2))
			1 && (get_color(args, file, &i), count++);
		else
			ivalid_lelement(tmp);
		i++;
		*r = i;
		if (count == 6)
			break ;
	}
}
