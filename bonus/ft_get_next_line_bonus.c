/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:28:10 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:37 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *str, char c)
{
	int		size;
	char	*str2;
	int		i;

	if (!c)
		return (str);
	size = ft_strlen(str) + 2;
	str2 = malloc(sizeof(char) * size);
	i = 0;
	while (str && str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = c;
	str2[i + 1] = '\0';
	if (str)
		free(str);
	return (str2);
}

char	*get_next_line(int fd)
{
	char	buf[2];
	int		ret;
	char	*str;

	str = NULL;
	buf[0] = ' ';
	buf[1] = '\0';
	while (buf[0] != '\n' && buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			if (str)
				free(str);
			return (str);
		}
		if (ret != 0)
			str = ft_strjoin_gnl(str, buf[0]);
		if (ret == 0)
			return (str);
	}
	return (str);
}
