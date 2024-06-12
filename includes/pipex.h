/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/06/12 19:36:23 by jhoratiu         ###   ########.fr       */
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

# include <sys/types.h>
# include <sys/wait.h>

// pipex
char			**cmd_check(char *cmd, char **env, char **path);
bool			check_access(char *path_infile, char *path_outfile);

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
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(char *str);

void			ft_work_pid_start(int fd[2][2], int infile);
void			ft_work_pid_mid(int fd[2][2]);
void			ft_work_pid_end(int fd[2][2], int outfile);

//ft_handle_infile
int			ft_handle_infile(char *file_name, char *cmd_name, char **env, int fd[2][2]);
int			ft_handle_outfile(char *file_name, char *cmd_name, char **env, int fd[2][2]);

#endif