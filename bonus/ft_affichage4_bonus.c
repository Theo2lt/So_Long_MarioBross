/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:59:44 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:18 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_verif_mouve_piranha(t_data *data, t_perso *piranha)
{
	int	y;
	int	x;

	y = piranha->position_y;
	x = piranha->position_x;
	if ((data->tab[y][x + piranha->direction] != '0'
		&& data->tab[y][x + piranha->direction] != 'P' )
		&& (data->tab[y][x - piranha->direction] != '0'
		&& data->tab[y][x - piranha->direction] != 'P' ))
		return (0);
	if ((data->tab[y][x + piranha->direction] == '0'
		|| data->tab[y][x + piranha->direction] == 'P' )
			&& data->tab[y + 1][x + piranha->direction] != '0')
		return (piranha->direction);
	return (piranha->direction * -1);
}

void	ft_mouve_piranha(t_data *data)
{
	t_perso	*piranha;
	int		y;
	int		x;

	piranha = data->troupe_piranha;
	while (piranha)
	{
		y = piranha->position_y;
		x = piranha->position_x;
		piranha->direction = ft_verif_mouve_piranha(data, piranha);
		if (data->tab[y][x + piranha->direction] == 'P')
			ft_exit(data);
		data->tab[y][x] = '0';
		data->tab[y][x + piranha->direction] = 'M';
		piranha->position_x += piranha->direction;
		if (piranha->direction == 0)
			piranha->direction = -1;
		piranha = piranha->next;
	}
}

void	ft_piranha_img(t_data *data)
{
	static long int	sleep;

	if (sleep == 0 || sleep == 10)
		data->piranhatmp = data->piranha1;
	if (sleep == 1 || sleep == 9)
		data->piranhatmp = data->piranha2;
	if (sleep == 2 || sleep == 8)
		data->piranhatmp = data->piranha3;
	if (sleep == 3 || sleep == 7)
		data->piranhatmp = data->piranha4;
	if (sleep == 4 || sleep == 6)
		data->piranhatmp = data->piranha5;
	if (sleep == 5)
	{
		data->piranhatmp = data->piranha6;
		ft_mouve_piranha(data);
	}
	if (sleep == 12)
		sleep = 0;
	sleep += 1;
}

void	ft_put_background_img(t_map *map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < map->size_x * 32)
	{
		my_put(data->rendu_mur, data->fond506, x,
			map->size_y * 32 - data->fond506->img_height);
		y = map->size_y * 32 - (2 * data->fond506->img_height);
		while (y > -data->fond506h->img_height)
		{
			my_put(data->rendu_mur, data->fond506h, x, y);
			y += -data->fond506h->img_height;
		}
		x += data->fond506->img_height;
	}
}
