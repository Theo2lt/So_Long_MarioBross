/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:07:32 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:42:28 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	ft_verif_map_forme(char **tab, t_map *data)
{
	int	y;

	y = 0;
	if (data->size_x == 0)
	{
		write(2, "Error\n", 7);
		write(2, "MAP VIDE\n", 10);
		return (0);
	}
	while (y != data->size_y)
	{
		if (ft_strlen(tab[y]) - 1 != data->size_x && (data->size_y - 1 != y))
		{
			write(2, "Error\n", 7);
			write(2, "MAP NON RECTANGLE\n", 19);
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_verif_map_mur_y(char **tab, t_map *data)
{
	int	y;

	y = 0;
	while (y != data->size_y)
	{
		if ((tab[y][0] != '1' && tab[y][0] != '\n')
			|| (tab[y][data->size_x - 1] != '1'))
		{
			write(2, "Error\n", 7);
			write(2, "MAP NON CONFORME AXE Y\n", 23);
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_verif_map_mur_x(char **tab, t_map	*data)
{
	int	x;

	x = 0;
	while (x != data->size_x - 1)
	{
		if ((tab[0][x] != '1' && tab[0][x] != '\n')
			|| (tab[data->size_y - 1][x] != '1'
			&& tab[data->size_y - 1][x] != '\n'))
		{
			write(2, "Error\n", 7);
			write(2, "MAP NON CONFORME AXE X\n", 23);
			return (0);
		}
		x++;
	}
	return (1);
}
