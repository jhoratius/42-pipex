/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:24:43 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/08 15:05:06 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror_msg(int *fd, char **cmd, char *msg)
{
	if (cmd != NULL)
		ft_free_table(cmd);
	close(fd[0]);
	close(fd[1]);
	perror(msg);
}

void	ft_close_fd_err(int *fd, int curr_pipe, int file, char *line)
{
	if (fd != NULL)
	{
		if (fd[0] > 0)
			close(fd[0]);
		if (fd[1] > 0)
			close(fd[1]);
	}
	if (curr_pipe > 0)
		close(curr_pipe);
	if (file > 0)
		close(file);
	write(1, line, ft_strlen(line));
}

void	ft_handle_infile_err(int *fd, char **cmd, int infile)
{
	ft_close_fd_err(fd, 0, infile, "cmd not found 1\n");
	ft_free_table(cmd);
	exit(EXIT_FAILURE);
}

void	ft_handle_outfile_err(char **cmd, int curr, int outfile)
{
	ft_free_table(cmd);
	ft_close_fd_err(NULL, curr, outfile, "cmd not found");
	exit(EXIT_FAILURE);
}

void	ft_handle_outfile_err2(char **cmd)
{
	ft_free_table(cmd);
	exit(EXIT_FAILURE);
}
