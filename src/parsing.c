/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/07 15:48:04 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**cmd_check(char *cmd, char **env, char **path)
{
	char	**args;
	char	**env_args;
	int		i;

	i = 0;
	if (!cmd || !env)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	env_args = check_path(env);
	if (!env_args)
		return (free(args), NULL);
	*path = create_path(args, env_args);
	if (!path)
		return (free(args), free(env_args), NULL);
	ft_free_table(env_args);
	if (!path)
		return (NULL);
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

char	*create_path(char **cmd, char **env_args)
{
	int		i;
	char	*path;
	char	*tmp;
	bool	cmd_found;

	i = 0;
	cmd_found = false;
	if(access(cmd[0], X_OK) == 0)
	{
		cmd_found = true;
		return (cmd[0]);
	}
	while (env_args[i])
	{
		tmp = ft_strjoin(env_args[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin(tmp, cmd[0]);
		if (!path)
			return (NULL);
		free(tmp);
		if(access(path, X_OK) == 0)
		{
			// fprintf(stderr, "Command found: %s\n", path);
			cmd_found = true;
			return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	return (cmd[0]);
}

void	ft_free_table(char **split)
{
	int	i;
	
	i = 0;
	while (split[i])
	{
		if (split[i] != NULL)
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
	free(split);
	split = NULL;
	return ;
}