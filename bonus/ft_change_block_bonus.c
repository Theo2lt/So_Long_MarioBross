/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_block_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:57:00 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:22 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_change_block(char **tab, t_map *data)
{
	int	y;
	int	x;
	int	block;

	x = 0;
	while (x < data->size_x)
	{
		block = 1;
		y = data->size_y - 1;
		while (0 < y)
		{
			if (tab[y][x] == '1' && block == 0)
				tab[y][x] = '2';
			else if (tab[y][x] != '1')
					block = 0;
			y--;
		}
		x++;
	}
}

void	ft_change_tap_block(char **tab, t_map *map, t_data *data)
{
	if (tab[data->perso->position_y - 2][data->perso->position_x] == '0')
	{
		tab[data->perso->position_y - 1][data->perso->position_x] = '3';
		tab[data->perso->position_y - 2][data->perso->position_x] = 'C';
		map->nbr_c++;
	}
	else if (tab[data->perso->position_y - 2][data->perso->position_x] == 'C')
		tab[data->perso->position_y - 1][data->perso->position_x] = '3';
	else
	{
		tab[data->perso->position_y - 1][data->perso->position_x] = 'P';
		tab[data->perso->position_y][data->perso->position_x] = '0';
		data->perso->position_y -= 1;
	}
}
