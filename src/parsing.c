/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/23 18:25:45 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parsing(char **av)
{
	if (!cmd_check(av[2]))
		return (false);
	if (!cmd_check(av[3]))
		return (false);
	return (true);
}

char	**cmd_check(char *cmd)
{
	char	**args;
	char	**path;

	if (!cmd)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	// path = ft_concat("/usr/bin/", args[0]);
	if (access(path, X_OK) == -1)
	{
		ft_free_split();
		return (NULL);
	}
	return (args);
}

void	ft_free_split()
{
	int	i;

	return ;
}
