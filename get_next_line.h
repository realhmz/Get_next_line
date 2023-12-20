#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnew(int size);
char	*get_next_line(int fd);
char *ft_strndup(char *s, int n);
char *ft_strdup(char *s);


#endif