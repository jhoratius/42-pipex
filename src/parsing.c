/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/22 16:47:00 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parsing(char **av)
{
	if (!cmd1_check(av[2]))
		return (false);
	if (!cmd2_check(av[3]))
		return (false);
	return (true);
}

char	**cmd1_check(char *cmd)
{
	char	**args;
	if (!cmd)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	if (ft_strcmp(args[0], ))
	return (args);
}

bool	cmd2_check(char *cmd)
{
	if (!cmd)
		return (false);
	return ;
}
