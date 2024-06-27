/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/27 13:27:26 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(int ac)
// {
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	signal(SIGPIPE, SIG_IGN);
	int			curr_pipe;
	int			i;

	if (ac < 5)
		return (1);
	curr_pipe = 0;
	i = 1;
	if (!check_access(av[1], av[ac - 1]))
		return (1);
	while (++i < ac - 1 && curr_pipe != -1)
	{
		// fprintf(stderr, "i : %d\n", i);
		if (i == 2)
		{
			fprintf(stderr, "infile handled\n");
			curr_pipe = ft_handle_infile(av[1], av[2], env);
		}
		else if (i == ac - 2)
		{
			fprintf(stderr, "outfile handled\n");
			curr_pipe = ft_handle_outfile(av[ac - 1], av[ac - 2], curr_pipe, env);
		}
		else
		{
			fprintf(stderr, "inter handled\n");
			curr_pipe = ft_handle_inter_cmds(av[i], curr_pipe, env);
		}
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

bool	check_access(char *path_infile, char *path_outfile)
{
	if (access(path_infile, R_OK) == -1)
		return (perror("403, Forbidden\n"), false);
	if (access(path_outfile, F_OK) != -1 && access(path_outfile, W_OK) == -1)
		return (perror("403, Forbidden\n"), perror("404, Not Found\n"), false);
	return (true);
}
