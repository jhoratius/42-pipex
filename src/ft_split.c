/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:39:45 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/02 17:01:10 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	buff;
	size_t	count;

	i = 0;
	buff = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && buff == 0)
		{
			buff = 1;
			count++;
		}
		else if (str[i] == c)
			buff = 0;
		i++;
	}
	return (count);
}

static void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_tab_imp(char **tab, char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	k = 0;
	while (k < ft_count_words(str, c))
	{
		while (str[i] == c)
			i++;
		len = 0;
		while (str[i + len] != '\0' && str[i + len] != c)
			len++;
		tab[k] = ft_calloc((len + 1), sizeof(char));
		if (!tab[k])
			return (0);
		j = 0;
		while (j < len)
			tab[k][j++] = str[i++];
		tab[k++][j] = '\0';
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	if (!(ft_tab_imp(tab, (char *)s, c)))
	{
		ft_free_tab(tab);
		return (NULL);
	}
	return (tab);
}
