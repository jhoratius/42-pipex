/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:40:35 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/12 19:41:55 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_handle_infile(char *file_name, char *cmd_name, char **env, int fd[2][2])
{
	char	*path;
	char	**cmd;
	int		exec;
	int		infile;

	infile = 42;
	path = NULL;
	exec = 0;
	infile = open((const char *)file_name, O_RDONLY);
	if (infile < 0)
		return (1);
	cmd = cmd_check(cmd_name, env, &path);
	if (!cmd)
		return (1);
	ft_work_pid_start(fd, infile);
	exec = execve(path, cmd, env);
	if (exec == -1)
	{
		free(path);
		ft_free_table(cmd);
		// close(infile);
		perror("exec fail 1");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_handle_outfile(char *file_name, char *cmd_name, char **env, int fd[2][2])
{
	char	*path;
	char	**cmd;
	// int		exec;
	int		outfile;

	outfile = open(file_name, O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		return (1);
	cmd = cmd_check(cmd_name, env, &path);
	if (!cmd)
		return (1);
	ft_work_pid_end(fd, outfile);
	if (execve(path, cmd, env) == -1)
	{
		// free everything
		free(path);
		ft_free_table(cmd);
		perror("exec fail 3");
		exit(EXIT_FAILURE);
	}
	return (0);
}
