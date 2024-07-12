/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:59 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/12 15:25:19 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int			curr_pipe;
	int			i;

	if (ac != 5)
		return (write(1, "Wrong number of arguments\n", 28));
	curr_pipe = 0;
	i = 1;
	while (++i < ac - 1 && curr_pipe != -1)
	{
		if (i == 2)
			curr_pipe = ft_handle_infile(av[1], av[2], env);
		else if (i == ac - 2)
			curr_pipe = ft_handle_outfile(av[ac -1], av[ac -2], curr_pipe, env);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
