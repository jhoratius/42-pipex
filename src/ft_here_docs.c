/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_docs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:40 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/01 19:02:47 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_here_doc(char **av, char **env)
{
	int		tmp_file;
	int		fd;
	char	*line;

	fd = 42;
	tmp_file = open(av[1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (tmp_file == -1)
		return (perror("tmp_file open error"), 1);
	while (1)
	{
		line = get_next_line(0, (void *) &line);
		if (line == NULL)
			break ;
		if (ft_limitercmp(av[2], line, ft_strlen(av[2])) != 0)
			write(tmp_file, line, ft_strlen(line));
		else
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(tmp_file);
	tmp_file = open(av[1], O_RDONLY);
	if (ft_exec_tmp(av, env, tmp_file) == 1)
		return (perror("exec tmp failed"), 1);
	return (0);
}

// close(tmp_file);
// tmp_file = open(av[1], O_RDONLY);
// if(tmp_file == -1)
// 	return (perror("Error reopen tmp file"), 1);
// while((line = get_next_line(tmp_file, (void *) &line))){
// 	printf("%s", line);
// 	free(line);
// }
// close(tmp_file);

int	ft_exec_tmp(char **av, char **env, int tmp_fd)
{
	int		curr_pipe;
	char	*infile;

	infile = av[1];
	curr_pipe = ft_handle_infile(av[1], av[3], env);
	if (curr_pipe == 1)
		return (perror("handle infile tmp curr_pipe failed"), 1);
	if (ft_handle_outfile(av[5], av[4], curr_pipe, env) == 1)
		return (perror("handle outfile tmp curr_pipe failed"), 1);
	close(tmp_fd);
	while (wait(NULL) > 0)
		;
	unlink(av[1]);
	return (0);
}

int	ft_limitercmp(char *lim, char *line, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((lim[i] != '\0' || line[i] != '\0') && i < n)
	{
		if (lim[i] == line[i])
			j = 0;
		else if (lim[i] < line[i])
		{
			j = lim[i] - line[i];
			return (j);
		}
		else if (lim[i] > line[i])
		{
			j = lim[i] - line[i];
			return (j);
		}
		i += 1;
	}
	if (ft_strlen(lim) != ft_strlen(line) - 1)
		return (1);
	return (0);
}
