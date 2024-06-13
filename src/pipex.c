/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/13 13:52:21 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(int ac)
// {
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	int			pid_start;
	int			pid_mid;
	int			pid_end;
	int			fd[2][2];
	int			i;

	if (ac <= 5)
		return (1);
	i = 1;
	if (!check_access(av[1], av[ac - 1]))
		return (1);
	if (pipe(fd[0]) < 0 || pipe(fd[1]) < 0)
		return (1);
	pid_start = fork();
	if (pid_start < 0)
	{
		perror("fork fail 1");
		return (1);
	}
	else if (pid_start == 0)
	{
		if (ft_handle_infile(av[1], av[2], env, fd) == 1)
		{
			fprintf(stderr, "issue on handle infile");
			return (1);
		}
	}
	// while (i < ac - 2)
	// {
	// 	i++;
	// }
	pid_mid = fork();
	if (pid_mid < 0)
	{
		perror("fork fail 2");
		return (1);
	}
	else if (pid_mid == 0)
	{
		if (ft_handle_inter_cmds(av[3], env, fd) == 1)
		{
			fprintf(stderr, "issue on handle infile");
			return (1);
		}
	}
	pid_end = fork();
	if (pid_end < 0)
	{
		perror("fork fail 3");
		return (1);
	}
	else if (pid_end == 0)
	{
		if (ft_handle_outfile(av[ac - 1], av[ac - 2], env, fd))
		{
			fprintf(stderr, "issue on handle outfile");
			return (1);
		}
	}
	ft_close_parent_fds(fd);
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
