/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:11:02 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:13:20 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

t_data	*ft_parsing(char **av)
{
	t_data	*args;
	char	**file;
	int		i;

	i = 0;
	args = mohi_bel_malloc(sizeof(t_data));
	check_file_isvalid(av[1]);
	file = ft_read_map(av[1]);
	if (!file[0])
		ft_error_message("Error:\nempty map!!");
	init_data(args);
	get_data(args, file, &i);
	check_params(*args);
	check_map(file + i, args);
	check_map_round_byones(args);
	check_elements(args);
	rep_spaseses_to_ones(args);
	return (args);
}
