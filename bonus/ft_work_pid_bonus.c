/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_pid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:28 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/12 15:22:43 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_work_pid_start(int *fd, char *file, char **cmd, char *path)
{
	int	infile;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		ft_free_table(cmd);
		free(path);
		ft_perror_msg(fd, NULL, "Error");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	if (dup2(infile, STDIN_FILENO) == -1)
		return (-1);
	if (infile > 0)
		close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (-1);
	close(fd[1]);
	return (0);
}

int	ft_work_pid_mid(int *fd, int curr_pipe)
{
	close(fd[0]);
	if (dup2(curr_pipe, STDIN_FILENO) == -1)
		return (-1);
	close(curr_pipe);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (-1);
	close(fd[1]);
	return (0);
}

int	ft_work_pid_end(int outfile, int curr_pipe)
{
	if (dup2(curr_pipe, STDIN_FILENO) == -1)
		return (-1);
	close(curr_pipe);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (-1);
	if (outfile > 0)
		close(outfile);
	return (0);
}
