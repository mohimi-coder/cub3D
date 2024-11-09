/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-bel <zait-bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:21:19 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/06 10:00:11 by zait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	exact_angle(t_cube *cube, int i, int j, double *angle)
{
	if (cube->data->map[i][j] == 'N')
		*angle = 3 * M_PI / 2;
	else if (cube->data->map[i][j] == 'S')
		*angle = M_PI / 2;
	else if (cube->data->map[i][j] == 'W')
		*angle = M_PI;
	else if (cube->data->map[i][j] == 'E')
		*angle = 0.0;
}

double	update_angle(t_cube *cube)
{
	double	angle;
	int		i;
	int		j;

	i = 0;
	angle = 0.0;
	while (cube->data->map[i])
	{
		j = 0;
		while (cube->data->map[i][j])
		{
			if (cube->data->map[i][j] == 'N' || cube->data->map[i][j] == 'S' \
				|| cube->data->map[i][j] == 'W' || cube->data->map[i][j] == 'E')
				exact_angle(cube, i, j, &angle);
			j++;
		}
		i++;
	}
	return (angle);
}
