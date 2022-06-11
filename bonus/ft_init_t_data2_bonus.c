/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:08:08 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 15:51:57 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_data	*ft_init_all_rendu(t_data *data, t_map *map)
{
	data->rendu = malloc(sizeof(t_img));
	if (!data->rendu)
		return (NULL);
	data->rendu->img = mlx_new_image(data->win->mlx,
			(map->size_x) * 32, (map->size_y) * 32);
	data->rendu->addr = mlx_get_data_addr(data->rendu->img,
			&data->rendu->bits_per_pixel,
			&data->rendu->line_length, &data->rendu->endian);
	data->rendu->img_width = (map->size_x) * 32;
	data->rendu->img_height = (map->size_y) * 32;
	data->rendu_mur = malloc(sizeof(t_img));
	if (!data->rendu)
		return (NULL);
	data->rendu_mur->img = mlx_new_image(data->win->mlx,
			(map->size_x) * 32, (map->size_y) * 32);
	data->rendu_mur->addr = mlx_get_data_addr(data->rendu_mur->img,
			&data->rendu_mur->bits_per_pixel,
			&data->rendu_mur->line_length, &data->rendu_mur->endian);
	data->rendu_mur->img_width = (map->size_x) * 32;
	data->rendu_mur->img_height = (map->size_y) * 32;
	return (data);
}

t_data	*ft_init_affichage(char **tab, t_map *map)
{
	t_data	*data;

	data = NULL;
	data = ft_init_data_mlx_win(data, map);
	data = ft_init_all_rendu(data, map);
	data->perso = malloc(sizeof(t_perso));
	if (!data->perso)
		return (NULL);
	data->perso->vie = 1;
	data->perso->deplacement = 0;
	data->tab = tab;
	data->map = map;
	data->troupe_piranha = NULL;
	ft_init_all_sprite(data);
	ft_init_all_img_addr(data);
	ft_init_piranha_position(tab, data);
	return (data);
}

int	ft_init_perso_position(char **tab, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
			{
				data->perso->position_x = x;
				data->perso->position_y = y;
				data->perso->vie = 1;
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_init_piranha_position(char **tab, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == 'M')
				ft_lstadd_back(data, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
