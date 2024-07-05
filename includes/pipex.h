/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/05 17:56:29 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include "get_next_line.h"

// pipex
char			**cmd_check(char *cmd, char **env, char **path);
// bool			check_access(char *path_infile, char *path_outfile);

// parsing
bool			parsing(char **av, char **env);
char			**check_path(char **env);
char			*create_path(char **cmd, char **env_args);
void			ft_free_table(char **split);
// char			**ft_implement_args(char *path, char **args);

// ft_split
char			**ft_split(const char *s, char c);

// utils
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				ft_limitercmp(char	*lim, char *line, unsigned int n);
int				ft_strlen(char *str);

int				ft_work_pid_start(int *fd, int infile);
int				ft_work_pid_mid(int *fd, int curr_pipe);
int				ft_work_pid_end(int outfile, int curr_pipe);

//ft_handle_infile
int				ft_handle_infile(char *file, char *cmd, char **env);
int				ft_handle_inter_cmds(char *cmd_name, int curr_pipe, char **env);
int				ft_handle_outfile(char *file, char *cmd, int curr, char **env);
void			ft_perror_msg(int *fd, char *msg);
void			ft_close_fd_err(int *fd, int curr_pipe, int file, char *line);

//ft_here_doc
int				ft_here_doc(char **av, char **env);
int				ft_exec_tmp(char **av, char **env, int tmp_fd);

#endif