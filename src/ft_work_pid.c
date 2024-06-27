/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:28 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/26 15:51:48 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_work_pid_start(int *fd, int infile)
{
	close(fd[0]);
	// fprintf(stderr, "closing start fd[0] : %d\n", fd[0]);
	if (dup2(infile, STDIN_FILENO) == -1)
		return (-1);
	close(infile);
	// fprintf(stderr, "closing start infile : %d\n", infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		fprintf(stderr, "start dup2 failed\n");
		return (-1);
	}
	close(fd[1]);
	// fprintf(stderr, "closing start fd[1] : %d\n", fd[1]);
	return (0);
}

int	ft_work_pid_mid(int *fd, int curr_pipe)
{
	close(fd[0]);
	if (dup2(curr_pipe, STDIN_FILENO) == -1)
		return (-1);
	close(curr_pipe);
	// fprintf(stderr, "closing mid curr_pipe : %d\n", curr_pipe);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (-1);
	close(fd[1]);
	// fprintf(stderr, "closing mid fd[1] : %d\n", fd[1]);
	return (0);
}

int	ft_work_pid_end(int outfile, int curr_pipe)
{
	if (dup2(curr_pipe, STDIN_FILENO) == -1)
		return (-1);
	close(curr_pipe);
	// fprintf(stderr, "closing end curr_pipe : %d\n", curr_pipe);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (-1);
	close(outfile);
	// fprintf(stderr, "closing end outfile : %d\n", outfile);
	return (0);
}
