/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:22:40 by het-taja          #+#    #+#             */
/*   Updated: 2023/12/21 17:17:28 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	while (s1[j])
		strjoin[i++] = s1[j++];
	j = 0;
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	free (s1);
	return (strjoin);
}

int	check_new(char *save)
{
	int i;

	i =0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
	
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

	if (!s)
		return (NULL);
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