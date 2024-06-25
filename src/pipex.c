/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/25 18:33:03 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	pipex(int ac)
// {
// 	return ;
// }

int	main(int ac, char **av, char **env)
{
	int			curr_pipe;
	int			i;

	if (ac < 5)
		return (1);
	curr_pipe = 0;
	i = 2;
	if (!check_access(av[1], av[ac - 1]))
		return (1);
	while (i < ac - 1 && curr_pipe != -1)
	{
		// printf("curr_pipe im main : %d\n", curr_pipe);
		if (i == 2)
			curr_pipe = ft_handle_infile(av[1], av[2], env);
		else if (i == ac - 2)
			curr_pipe = ft_handle_outfile(av[ac - 1], av[ac - 2], curr_pipe, env);
		else
			curr_pipe = ft_handle_inter_cmds(av[i], curr_pipe, env);
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

bool	check_access(char *path_infile, char *path_outfile)
{
	if (access(path_infile, R_OK) == -1)
	{
		printf("infile [read not allowed]\n");
		//si l'infile n'existe pas, continuer l'execution
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

int	**ft_alloc_fds(int ac)
{
	int	**fd;
	int	i;

	fd = malloc((ac - 3) * sizeof(int *));
	if(!fd)
		return (NULL);
	i = 0;
	while (i < (ac - 3))
	{
		fd[i] = malloc(2 * sizeof(int));
		if (!fd[i])
		{
			// ft_free_table(fd);
			return (NULL);
		}
		fd[i][0] = 42;
		fd[i][1] = 42;
		i++;
	}
	return (fd);
}
