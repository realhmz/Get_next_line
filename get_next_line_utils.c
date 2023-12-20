#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i;
    int j;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

char *ft_strchr(char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (c == '\0')
        return (s);
    return (NULL);
}

char *ft_strnew(int size)
{
    char *str;
    int i;

    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i <= size)
    {
        str[i] = '\0';
        i++;
    }
    return (str);
}

char *ft_strdup(char *s)
{
    char *str;
    int i;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}