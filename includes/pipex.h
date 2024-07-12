/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/12 15:20:33 by jhoratiu         ###   ########.fr       */
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

// parsing
bool			parsing(char **av, char **env);
char			**check_path(char **env);
char			*create_path(char **cmd, char **env_args);
void			ft_free_table(char **split);

// ft_split
char			**ft_split(const char *s, char c);

// utils
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);

// ft_work_pid
int				ft_work_pid_start(int *fd, char *file_, char **cmd, char *path);
int				ft_work_pid_mid(int *fd, int curr_pipe);
int				ft_work_pid_end(int outfile, int curr_pipe);

// ft_handle_errors
void			ft_perror_msg(int *fd, char **cmd, char *msg);
void			ft_close_fd_err(int *fd, int curr_pipe, int file, char *line);
void			ft_handle_infile_err(int *fd, char **cmd, int infile);
void			ft_handle_outfile_err(char **cmd, int curr, int outfile);
void			ft_handle_outfile_err2(char **cmd);

//ft_handle_infile
int				ft_handle_infile(char *file, char *cmd, char **env);
int				ft_handle_inter_cmds(char *cmd_name, int curr_pipe, char **env);
int				ft_handle_outfile(char *file, char *cmd, int curr, char **env);
int				ft_init_infile_vars(int *infile, char **path, int *fd);

//ft_here_doc
int				ft_here_doc(char **av, char **env);
int				ft_exec_tmp(char **av, char **env, int tmp_fd);
int				ft_limitercmp(char *lim, char *line, unsigned int n);
void			ft_handle_hd_err(char *buffer, int *tmp_file);
int				ft_init_hd_vars(int *fd, char **buff, char **av, int *tmp_file);

#endif