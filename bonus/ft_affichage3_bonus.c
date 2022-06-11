/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:57:14 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:07 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_rendu_mur(char **tab, t_map *map, t_data *data)
{
	int	x;
	int	y;

	ft_put_background_img(map, data);
	x = 0;
	y = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			if (tab[y][x] == '1')
			{	
				if (y != map->size_y - 1 && (y == 0 || tab[y - 1][x] == '1'))
					ft_terre_img(data, tab, x, y);
				else
					ft_herbe_img(data, tab, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}	
}

void	ft_reset_rendu2(char **tab, t_data *data, int x, int y)
{
	if (tab[y][x] == '2')
		my_put(data->rendu, data->blockptmp, x * 32, y * 32);
	if (tab[y][x] == '3')
		my_put(data->rendu, data->blockb, x * 32, y * 32);
	if (tab[y][x] == 'C')
		my_put(data->rendu, data->piecetmp, x * 32, y * 32);
	if (tab[y][x] == 'P')
		my_put(data->rendu, data->mariotmp, x * 32, y * 32);
	if (tab[y][x] == 'E')
	{	
		if (data->map->nbr_c == 0)
			my_put(data->rendu, data->svh, x * 32, y * 32);
		else
			my_put(data->rendu, data->srh, x * 32, y * 32);
	}
	if (tab[y][x] == 'M')
		my_put(data->rendu, data->piranhatmp, x * 32, y * 32);
}

void	ft_reset_rendu(char **tab, t_map *map, t_data *data)
{
	int	x;
	int	y;

	my_put(data->rendu, data->rendu_mur, 0, 0);
	x = 0;
	y = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			ft_reset_rendu2(tab, data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_mario_img_haut(t_data *data, long int sleep)
{
	if (data->perso->direction == 1)
	{
		if (sleep == 0)
			data->mariotmp = data->mario_hd1;
		else if (sleep == 200000)
			data->mariotmp = data->mario_hd2;
		else if (sleep == 400000)
			data->mariotmp = data->mario_hd3;
		else if (sleep == 600000)
			data->mariotmp = data->mario_hd2;
	}
	else
	{
		if (sleep == 0)
			data->mariotmp = data->mario_hg1;
		else if (sleep == 200000)
			data->mariotmp = data->mario_hg2;
		else if (sleep == 400000)
			data->mariotmp = data->mario_hg3;
		else if (sleep == 600000)
			data->mariotmp = data->mario_hg2;
	}
}

void	ft_mario_img(t_data *data, long int sleep)
{
	int	y;
	int	x;

	y = data->perso->position_y;
	x = data->perso->position_x;
	if (data->perso->deplacement == 0 || data->tab[y + 1][x] == 'E')
	{
		if (sleep == 0)
			data->mariotmp = data->mario_init1;
		else if (sleep == 200000)
			data->mariotmp = data->mario_init2;
	}
	else
	{
		if (data->tab[y + 1][x] == '1' || data->tab[y + 1][x] == '2'
			||data->tab[y + 1][x] == '3')
			ft_mario_img_sol(data, sleep);
		else
			ft_mario_img_haut(data, sleep);
	}
}
