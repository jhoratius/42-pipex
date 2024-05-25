/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:34 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/25 16:42:03 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			j = 0;
		else if (s1[i] > s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		else if (s1[i] < s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
		i += 1;
	}
	return (0);
}

char	*ft_concat(char *str1, char *str2)
{
	int		i;
	int		total_len;
	char	*str_final;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	str1 = NULL;
	str_final = NULL;
	total_len = ft_strlen(str1) + ft_strlen(str2);
	str_final = malloc((total_len + 1) * sizeof(char));
	while (str1[i++])
		str_final[i] = str1[i];
	while (str2[i++])
		str_final[i] = str2[i];
	str_final = '\0';
	return (str_final);
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
	str = (char *)malloc((ft_strlen((char *)s1)) + (ft_strlen((char *)s2)) + 1);
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
