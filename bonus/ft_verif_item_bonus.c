/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_item_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:42:29 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 15:14:14 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_verif_n_item(t_map *map)
{
	if (map->nbr_c == 0 || map->nbr_e == 0 || map->nbr_p != 1)
	{
		write(2, "Error\n", 7);
		write(2, "Nombre item non valide\n", 24);
		return (0);
	}
	return (1);
}

int	ft_verif_inconue(char c)
{
	if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0' && c != 'M')
	{
		write(2, "Error\nNombre item non valide\n", 30);
		return (0);
	}
	return (1);
}

int	ft_verif_item(char **tab, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y != map->size_y)
	{
		x = 0;
		while (x != map->size_x)
		{
			if (!ft_verif_inconue(tab[y][x]))
				return (0);
			if (tab[y][x] == 'C')
				map->nbr_c++;
			if (tab[y][x] == 'E')
				map->nbr_e++;
			if (tab[y][x] == 'P')
				map->nbr_p++;
			x++;
		}
		y++;
	}
	return (ft_verif_n_item(map));
}
