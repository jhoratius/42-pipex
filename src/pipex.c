/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/12 19:41:37 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(char **av)
// {
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	int			outfile;
	int			pid_start;
	int			pid_mid;
	int			pid_end;
	int			fd[2][2];

	char		**cmd2;
	//char		**cmd3;
	//char		**path1;
	char		*path2;
	// char		*path3;
	int			i;

	// if (ac <= 5)
	// 	return (1);
	i = 2;
	if (!check_access(av[1], av[ac - 1]))
		return (1);
	if (pipe(fd[0]) < 0 || pipe(fd[1]) < 0)
		return (1);
	//path = NULL;
	path2 = NULL;
	// path3 = NULL;
	
	outfile = 42;
	// pid start
	pid_start = fork();
	if (pid_start < 0)
	{
		perror("fork fail 1");
		return (1);
	}
	else if (pid_start == 0)
	{
		if(ft_handle_infile(av[1], av[2], env, fd) == 1)
		{
			fprintf(stderr, "issue on handle infile");
			return (1);
		}
	}

	//	while (i < ac - 2)
	//	{
	//		i++;
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
	if (ft_handle_outfile(av[ac - 1], av[ac - 2], env, fd))
	{
		fprintf(stderr, "issue on handle outfile");
		return (1);
	}

	// close everything
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
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
