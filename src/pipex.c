/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/05 17:09:55 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(char **av)
// {
// 	return ;
// }

bool	check_access(char *path_infile, char *path_outfile)
{
	if (access(path_infile, R_OK) == -1)
	{
		printf("infile[read not allowed]\n");
		return (false);
	}
	if (access(path_outfile, F_OK) != -1 && access(path_outfile, W_OK) == -1)
	{
		printf("outfile [writing not allowed]\n");
		printf("outfile [exec not allowed]\n");
		return (false);
	}
	return (true);
}

int	main(int ac, char **av, char **env)
{
	int			infile;
	int			outfile;
	int			pid1;
	int			pid2;
	int			fd[2];
	char		**cmd1;
	char		**cmd2;
	char		*path1;
	char		*path2;

	if (ac != 5)
		return (1);
	if (!check_access(av[1], av[4]))
		return (1);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		return (1);
	outfile = open(av[4], O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		return (1);
	if (pipe(fd) < 0)
		return (1);
	// pid1
	cmd1 = cmd_check(av[2], env, &path1);
	if (!cmd1)
		return (1);
	pid1 = fork();
	if (pid1 == 0)
	{
		ft_work_pid1(fd, infile);
		if (execve(path1, cmd1, env) == -1)
		return (1);
	}
	free(path1);
	ft_free_table(cmd1);

	// pid2
	cmd2 = cmd_check(av[3], env, &path2);
	if (!cmd2)
		return (1);
	pid2 = fork();
	if (pid2 == 0)
	{
		ft_work_pid2(fd, outfile);
		if (execve(path2, cmd2, env) == -1)
			return (1);
	}
	free(path2);
	ft_free_table(cmd2);

	// close everything
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	// wait everything
	if (waitpid(pid1, NULL, 0) == -1)
		return (1);
	if (waitpid(pid2, NULL, 0) == -1)
		return (1);
	return (0);
}

void	ft_work_pid1(int *fd, int infile)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	ft_work_pid2(int *fd, int outfile)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(outfile);
}
