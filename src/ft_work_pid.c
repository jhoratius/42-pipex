/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:28 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/12 19:38:49 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_work_pid_start(int fd[2][2], int infile)
{
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[0][0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[0][1], STDOUT_FILENO);
	close(fd[0][1]);
}

void	ft_work_pid_mid(int fd[2][2])
{
	close(fd[0][1]);
	close(fd[1][0]);
	dup2(fd[0][0], STDIN_FILENO);
	close(fd[0][0]);
	close(fd[1][0]);
	dup2(fd[1][1], STDOUT_FILENO);
	close(fd[1][1]);
}

void	ft_work_pid_end(int fd[2][2], int outfile)
{
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][1]);
	dup2(fd[1][0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1][0]);
	close(outfile);
}
