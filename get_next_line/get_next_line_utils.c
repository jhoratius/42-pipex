/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:50:43 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/05 16:36:53 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

char	*ft_free_join(char *buffer, char *str)
{
	char	*tmp;

	tmp = ft_strjoin((char *)buffer, (char *)str);
	free(buffer);
	return (tmp);
}
