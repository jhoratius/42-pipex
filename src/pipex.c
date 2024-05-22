/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/22 15:43:36 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(char **av)
// {
// 	return ;
// }

// bool	check_access(char **path_infile, char **path_outfile)
// {
// 	if (access(path_infile, R_OK) == 0)
// 	{
// 		printf("infile[read not allowed]");
// 		return (false);
// 	}
// 	if (access(path_outfile, W_OK | X_OK) == 0)
// 	{
// 		printf("outfile[writing not allowed]");
// 		printf("outfile[exec not allowed]");
// 		return (false);
// 	}
// 	return (true);
// }

int	main(int ac, char **av, char **env)
{
	// int			infile;
	// int			outfile;
	int			pid;
	int			fd[2];
	int			i;
	char		*args_cmd1[3];
	// char		*args_cmd2[2];

	i = 0;
	while(av[i])
	{
		printf("av : %s\n", av[i]);
		i++;
	}
	printf("ac : %i\n", ac);

	args_cmd1[0] = "/bin/echo";
	args_cmd1[1] = "Julien";
	args_cmd1[2] =  NULL;
	// args_cmd2[0] = "/bin/cat";
	// args_cmd2[1] = NULL;

	// if (ac != 5)
	// 	return (1);
	if (!parsing(av))
		return (1);
	// if (!check_access(av[1], av[3]))
	// 	return (1);
	// infile = open(av[1], O_RDONLY);
	// if (infile < 0)
	// 	return (1);
	// outfile = open(av[3], O_RDWR);
	// if (outfile < 0)
	// 	return (1);
	if(pipe(fd) < 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDIN_FILENO);
		close(fd[1]);
		execve("/usr/bin/echo", args_cmd1, env);
	}
	wait(NULL);
	close(fd[0]);
	close(fd[1]);
	// pipex(av);
	// close(infile);
	// close(outfile);
	return (0);
}
