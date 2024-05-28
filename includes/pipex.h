/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/28 16:42:30 by jhoratiu         ###   ########.fr       */
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

// main
char			**cmd_check(char *cmd, char **env);

// parsing
bool			parsing(char **av, char **env);
char			**check_path(char **env);
char			*create_path(char **env_args);
void			ft_free_split(void);

// ft_split
char			**ft_split(const char *s, char c);

// utils
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(char *str);

#endif