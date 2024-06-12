/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/12 17:10:32 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(char **av)
// {
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	int			infile;
	int			outfile;
	int			pid_start;
	int			pid_mid;
	int			pid_end;
	int			fd[2][2];
	char		**cmd;
	char		**cmd2;
	char		**cmd3;
	char		*path;
	char		*path2;
	char		*path3;
	int			i;

	// if (ac <= 5)
	// 	return (1);
	i = 2;
	if (!check_access(av[1], av[ac - 1]))
		return (1);
	
	if (pipe(fd[0]) < 0 || pipe(fd[1]) < 0)
		return (1);
	path = NULL;
	path2 = NULL;
	path3 = NULL;
	infile = 42;
	outfile = 42;
	// pid put infile to std-in and std_out to next cmd
	// ft_fork_and_cmd();
	pid_start = fork();
	if (pid_start < 0)
	{
		perror("fork fail 1");
		return (1);
	}
	else if (pid_start == 0)
	{
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
			return (1);
		cmd = cmd_check(av[i], env, &path);
		if (!cmd)
			return (1);
		// printf("%s\n", cmd2[0]);
		ft_work_pid_start(fd, infile);
		fprintf(stderr, "blblbl1\n");
		if (execve(path, cmd, env) == -1)
		{
			// free everything
			free(path);
			ft_free_table(cmd);
			perror("exec fail 1");
			exit(EXIT_FAILURE);
		}
	}

	//	while (i < ac - 2)
	//	{
	//		
	//	}
	// pid put std_in to cmd1 and std_out to next cmd
	pid_mid = fork();
	if (pid_mid < 0)
	{
		perror("fork fail 2");
		return (1);
	}
	else if (pid_mid == 0)
	{
		cmd2 = cmd_check(av[3], env, &path2);
		if (!cmd2)
			return (1);
		// printf("%s\n", cmd2[0]);
		ft_work_pid_mid(fd);
		fprintf(stderr, "blblbl2\n");
		if (execve(path2, cmd2, env) == -1)
		{
			// free everything
			free(path2);
			ft_free_table(cmd2);
			perror("exec fail 2");
			exit(EXIT_FAILURE);
		}
	}

	// pid put std_in to cmd2 and std_out to outfile
	pid_end = fork();
	if (pid_end < 0)
	{
		perror("fork fail 3");
		return (1);
	}
	else if (pid_end == 0)
	{
		outfile = open(av[ac - 1], O_RDWR | O_CREAT, 0644);
		if (outfile < 0)
			return (1);
		cmd3 = cmd_check(av[4], env, &path3);
		if (!cmd3)
			return (1);
		ft_work_pid_end(fd, outfile);
		fprintf(stderr, "blblbl3\n");
		if (execve(path3, cmd3, env) == -1)
		{
			// free everything
			free(path3);
			ft_free_table(cmd3);
			perror("exec fail 3");
			exit(EXIT_FAILURE);
		}
	}
	// close everything
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(infile);
	close(outfile);
	// wait everything
	waitpid(pid_start, NULL, 0);
	waitpid(pid_mid, NULL, 0);
	waitpid(pid_end, NULL, 0);
	// while (wait(NULL))
	// 	;
	return (0);
}

bool	check_access(char *path_infile, char *path_outfile)
{
	if (access(path_infile, R_OK) == -1)
	{
		printf("infile [read not allowed]\n");
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
