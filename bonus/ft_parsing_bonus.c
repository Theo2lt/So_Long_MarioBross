/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:37:23 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:42:16 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_verif_map_folder(char *name_map)
{
	int		fd;

	fd = open(name_map, __O_DIRECTORY);
	if (fd != -1)
	{
		write(2, "Error\n", 7);
		write(2, "ACCES MAP INVALIDE (DOSSIER)\n", 30);
		close(fd);
		return (0);
	}
	return (1);
}

int	ft_verif_map_file(char *name_map)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(name_map, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 7);
		write(2, "ACCES MAP INVALIDE \n", 21);
		close(fd);
		return (0);
	}
	i = 0;
	str = "";
	while (str)
	{
		i++;
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return (i);
}

char	**ft_create_tab(char *name_map)
{
	int		fd;
	int		i;
	int		len;
	char	**tab;

	i = 0;
	if (!ft_verif_name_map(name_map))
		return (NULL);
	if (!ft_verif_map_folder(name_map) || !ft_verif_map_file(name_map))
		return (NULL);
	i = ft_verif_map_file(name_map);
	tab = malloc(sizeof(char *) * i);
	len = i;
	i = 0;
	fd = open(name_map, O_RDONLY);
	while (len != i)
	{
		tab[i] = get_next_line(fd);
		if (tab[i])
			tab[i][ft_strlen(tab[i])] = '\0';
		i++;
	}
	close(fd);
	return (tab);
}
