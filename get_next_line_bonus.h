/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:25:06 by het-taja          #+#    #+#             */
/*   Updated: 2023/12/21 18:26:53 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12

# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

int		ft_strlen(char *s);
int		check_new(char *save);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strnlen(const char *save);
char	*static_modify(char *s);
char	*ft_strdup(const char *s1);

#endif