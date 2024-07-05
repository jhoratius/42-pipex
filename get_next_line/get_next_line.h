/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:06:12 by jhoratiu          #+#    #+#             */
/*   Updated: 2024/07/05 15:18:30 by jhoratiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include   <stdio.h>
# include   <stdlib.h>
# include   <fcntl.h>
# include   <unistd.h>
# include   <limits.h>
# include   <stddef.h>

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 1
# endif
// void __attribute__((destructor)) free_buffer();

//get_next_line
char	*get_next_line(int fd, void **line);
int		ft_check(char *str, char c);
char	*fd_read(int fd, char *buffer);
char	*sub_line(char *buffer);
char	*get_rest(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free_join(char *buffer, char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(char *str);

#endif