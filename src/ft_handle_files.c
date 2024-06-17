/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:40:35 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/17 15:54:56 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_handle_infile(char *file_name, char *cmd_name, char **env)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		fd[2];
	int		pid_start;

	infile = 42;
	path = NULL;
	if (pipe(fd) == -1)
		return (1);
	pid_start = fork();
	if (pid_start < 0)
	{
		ft_perror_msg(fd, "fork fail 1");
		return (1);
	}
	else if (pid_start == 0)
	{
		infile = open((const char *)file_name, O_RDONLY);
		if (infile < 0)
			return (ft_perror_msg(fd, "file not found"), 1);
		cmd = cmd_check(cmd_name, env, &path);
		if (!cmd)
			return (ft_perror_msg(fd, "command not found"), 1);
		ft_work_pid_start(fd, infile);
		if (execve(path, cmd, env) == -1)
		{
			free(path);
			ft_free_table(cmd);
			perror("exec fail 1");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(fd[1]);
	}
	return (fd[0]);
}

int	ft_handle_inter_cmds(char *cmd_name, int curr_pipe, char **env)
{
	char	*path;
	char	**cmd;
	int		fd[2];
	int		pid_mid;

	path = NULL;
	if (pipe(fd) < 0)
		return (1);
	pid_mid = fork();
	if (pid_mid < 0)
		return (ft_perror_msg(fd, "fork fail 2"), 1);
	else if (pid_mid == 0)
	{
		cmd = cmd_check(cmd_name, env, &path);
		if (!cmd)
			return (1);
		ft_work_pid_mid(fd, curr_pipe);
		if (execve(path, cmd, env) == -1)
		{
			free(path);
			ft_free_table(cmd);
			perror("exec fail 2");
			return (1);
		}
		return (0);
	}
	else
		close(fd[1]);
	return (fd[0]);
}

int	ft_handle_outfile(char *file_name, char *cmd_name, int curr_pipe, char **env)
{
	char	*path;
	char	**cmd;
	int		outfile;
	int		pid_end;
	int		*fd;

	outfile = 42;
	path = NULL;
	fd = 0;
	pid_end = fork();
	if (pid_end < 0)
	{
		perror("fork fail 3");
		return (1);
	}
	else if (pid_end == 0)
	{
		outfile = open(file_name, O_RDWR | O_CREAT, 0644);
		if (outfile < 0)
			return (1);
		cmd = cmd_check(cmd_name, env, &path);
		if (!cmd)
			return (1);
		ft_work_pid_end(fd, outfile, curr_pipe);
		if (execve(path, cmd, env) == -1)
		{
			free(path);
			ft_free_table(cmd);
			perror("exec fail 3");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

void	ft_perror_msg(int *fd, char *msg)
{
	close(fd[0]);
	close(fd[1]);
	perror(msg);
}
