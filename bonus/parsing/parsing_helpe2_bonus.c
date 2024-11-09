/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpe2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:17 by mohimi            #+#    #+#             */
/*   Updated: 2024/11/05 10:20:18 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	ft_free_leak(char **str)
{
	int	i;

	i = 0;
	if (!str)
		ft_error_message("Erorr:\nempty map!!");
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error_message(char *mess)
{
	int	i;

	i = 0;
	while (mess[i])
	{
		write (1, &mess[i], 1);
		i++;
	}
	write (1, "\n", 1);
	exit(1);
}

static int	ft_countword(char const *str, char c)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] != c && b == 0)
		{
			b = 1;
			count++;
		}
		else if (str[i] == c)
			b = 0;
		i++;
	}
	return (count);
}

static void	ft_free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		wi;
	int		wl;
	char	**words;

	if (!s)
		return (NULL);
	wi = 0;
	wc = ft_countword(s, c);
	words = (char **)mohi_bel_malloc (sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);
	while (wi < wc)
	{
		while (*s == c)
			s++;
		wl = 0;
		while (s[wl] && s[wl] != c)
			wl++;
		words[wi] = ft_substr(s, 0, wl);
		if (!words[wi++])
			return (ft_free_split(words), NULL);
		s += wl;
	}
	return (words[wi] = NULL, words);
}
