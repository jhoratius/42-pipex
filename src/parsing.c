/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/28 19:15:19 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parsing(char **av, char **env)
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = cmd_check(av[2], env);
	if (!cmd1)
		return (false);
	cmd2 = cmd_check(av[3], env);
	if (!cmd2)
		return (false);
	return (true);
}

char	**cmd_check(char *cmd, char **env)
{
	char	**args;
	char	**env_args;
	char	*path;
	int		i;

	i = 0;
	if (!cmd || !env)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	env_args = check_path(env);
	if (!env_args)
	{
		
		return (NULL);
	}
	path = create_path(env_args);
	if (!path)
		return (NULL);
	// printf("path : %s\n", path);
	args[0] = path;
	free(path);
	return (args);
}

char	**check_path(char **env)
{
	int		i;
	char	**env_args;

	i = 0;
	env_args = NULL;
	if (!env)
		return (NULL);
	while(env[i])
	{
		if (!(ft_strncmp(env[i], "PATH", 4)))
			break ;
		i++;
	}
	env_args = ft_split(env[i], ':');
	if (!env_args)
		return (NULL);
	return (env_args);
}

char	*create_path(char **env_args)
{
	int		i;
	char	*path;
	bool	cmd_found;

	i = 0;
	path = env_args[i];
	i++;
	cmd_found = false;
	while (env_args[i])
	{
		path = ft_strjoin(path, env_args[i]);
		if (!path)
		{
			ft_free_split();
			// ft_free_strjoin(path);
			return (NULL);
		}
		if(access(path, X_OK))
		{
			cmd_found = true;
			break ;
		}
	}
	if (cmd_found == false)
	{
		ft_free_split();
		// ft_free_strjoin(path);
		return (NULL);
	}
	return (path);
}

void	ft_free_split(void)
{
	return ;
}