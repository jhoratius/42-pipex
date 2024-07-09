/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:40:35 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/09 13:50:48 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_handle_infile(char *file_, char *cmd_, char **env)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		fd[2];
	int		pid_start;

	if (ft_init_infile_vars(&infile, &path, fd))
		return (1);
	pid_start = fork();
	if (pid_start < 0)
		return (ft_perror_msg(fd, NULL, "Error"), 1);
	if (pid_start == 0)
	{
		infile = open((const char *)file_, O_RDONLY);
		if (infile < 0)
			return (ft_perror_msg(fd, NULL, "Error"), 1);
		cmd = cmd_check(cmd_, env, &path);
		if (!cmd || !path)
			ft_handle_infile_err(fd, cmd, infile);
		ft_work_pid_start(fd, infile);
		if (execve(path, cmd, env) == -1)
			return (ft_perror_msg(fd, cmd, "Error"), 1);
	}
	close(fd[1]);
	return (fd[0]);
}

int	ft_handle_outfile(char *file_, char *cmd_, int curr, char **env)
{
	char	*path;
	char	**cmd;
	int		outfile;
	int		pid_end;

	outfile = 42;
	path = NULL;
	pid_end = fork();
	if (pid_end < 0)
		return (perror("Error :"), 1);
	if (pid_end == 0)
	{
		outfile = open(file_, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
			return (perror("Error :"), 1);
		cmd = cmd_check(cmd_, env, &path);
		if (!cmd || !path)
			ft_handle_outfile_err(cmd, curr, outfile);
		ft_work_pid_end(outfile, curr);
		if (execve(path, cmd, env) == -1)
			ft_handle_outfile_err2(cmd);
	}
	close(curr);
	return (0);
}

int	ft_init_infile_vars(int *infile, char **path, int *fd)
{
	*infile = 42;
	*path = NULL;
	if (pipe(fd) == -1)
		return (perror("Error :"), 1);
	return (0);
}
