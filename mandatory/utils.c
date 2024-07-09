/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:34 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/09 13:56:30 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
			j = 0;
		else if (s1[i] < s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		else if (s1[i] > s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		i += 1;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			j = 0;
		else if (s1[i] < s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		else if (s1[i] > s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		i += 1;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_calloc((ft_strlen((char *)s1))
			+ (ft_strlen((char *)s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1 != NULL && s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*c;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (ULONG_MAX / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	c = ptr;
	while (i < size * nmemb)
	{
		*c = 0;
		c++;
		i++;
	}
	return (ptr);
}
