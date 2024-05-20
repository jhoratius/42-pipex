/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/20 15:24:10 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parsing(char **av)
{
	if (!infile_check(av[1]))
		return (false);
	if (!cmd1_check(av[2]))
		return (false);
	if (!cmd2_check(av[3]))
		return (false);
	if (!outfile_check(av[4]))
		return (false);
	return (true);
}

bool	infile_check(char *infile)
{
	if (!infile)
		return (false);
	return ;
}

bool	cmd1_check(char *cmd)
{
	if (!cmd)
		return (false);
	return ;
}

bool	cmd2_check(char *cmd)
{
	if (!cmd)
		return (false);
	return ;
}

bool	outfile_check(char *outfile)
{
	if (!outfile)
		return (false);
	return ;
}
