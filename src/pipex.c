/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/31 18:28:46 by jhoratiu         ###   ########.fr       */
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
	int			i = 0;

	// if (ac != 5)
	// 	return (1);

	// parsing
	cmd1 = cmd_check(av[2], env);
	if (!cmd1)
		return (1);
	// cmd1[1] = av[2];
	cmd2 = cmd_check(av[3], env);
	if (!cmd2)
		return (1);
	// cmd2[1] = av[3];

	// check access
	if (!check_access(av[1], av[4]))
		return (1);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		return (1);
	outfile = open(av[4], O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		return (1);

	// pipe then fork
	if (pipe(fd) < 0)
	{
		printf("OK");
		return (1);
	}
	// while (cmd1[i++])
	// 	printf("cmd1 : %s\n", cmd1[i]);
	// i = 0;
	// while (cmd2[i++])
	// 	printf("cmd2 : %s\n", cmd2[i]);
	pid1 = fork();

	// processes
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(cmd1[0], cmd1, env);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(outfile);
		// fprintf(stderr, "cmd2[0] : %s\n", cmd2[0]);
		// fprintf(stderr, "%d\n", execve(cmd2[0], cmd2, env));
	}
	// close(fd[0]);
	// close(fd[1]);
	// close(infile);
	// close(outfile);
	if (waitpid(pid1, NULL, 0) == -1)
		return (1);
	if (waitpid(pid2, NULL, 0) == -1)
		return (1);
	// wait(NULL);
	return (0);
}
