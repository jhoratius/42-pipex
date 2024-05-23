/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:39 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/05/23 15:13:31 by jhoratiu         ###   ########.fr       */
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
bool			parsing(char **av);
char			**cmd_check(char *cmd);

// parsing
bool			parsing(char **av);
bool			cmd1_check(char *cmd);
bool			cmd2_check(char *cmd);

// ft_split
static size_t	ft_count_words(const char *str, char c);
static void		ft_free_tab(char **tab);
static int		ft_tab_imp(char **tab, char *str, char c);
char			**ft_split(const char *s, char c);

// utils
int				ft_strcmp(char *s1, char *s2);

#endif