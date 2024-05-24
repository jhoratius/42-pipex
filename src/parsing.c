/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/24 18:13:31 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parsing(char **av, char **env)
{
	if (!cmd_check(av[2], env))
		return (false);
	if (!cmd_check(av[3], env))
		return (false);
	return (true);
}

char	**cmd_check(char *cmd, char **env)
{
	char	**args;
	char	**path;
	char	**env_args;
	int		i;

	i = 0;
	if (!cmd || !env)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	while(env[i])
	{
		if (!(ft_strncmp(env[i], "PATH", 4)))
			break ;
	}
	env_args = ft_split(env[i], ':');
	if (!env_args)
		return (NULL);
	while (env_args)
	{
		path = ft_concat("/usr/bin/", args[0]);
	}
	if (!path)
	{
		ft_free_split();
		return (NULL);
	}
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
