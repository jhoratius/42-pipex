/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/20 16:03:31 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(char **av)
{
	return ;
}

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
	int			pipefd[2];

	char	**echo_args = {"/bin/echo", "Julien", NULL};
	char	**cat_args = {"/bin/cat", NULL};

	// if (ac != 5)
	// 	return (1);
	// if (!parsing(av))
	// 	return (1);
	// if (!check_access(av[1], av[3]))
	// 	return (1);
	// infile = open(av[1], O_RDONLY);
	// if (infile < 0)
	// 	return (1);
	// outfile = open(av[3], O_RDWR);
	// if (outfile < 0)
	// 	return (1);
	if(pipe(pipefd) < 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		execve("/bin/echo", echo_args, env);
	}
	else
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		execve("/bin/cat", cat_args, env);
	}
	// pipex(av);
	// close(infile);
	// close(outfile);
	return (0);
}
