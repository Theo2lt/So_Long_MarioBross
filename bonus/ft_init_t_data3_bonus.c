/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:18:12 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:55 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_data	*ft_init_data_mlx_win(t_data *data, t_map *map)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->win = malloc(sizeof(t_win));
	if (!data->win)
		return (NULL);
	data->win->mlx = mlx_init();
	data->win->mlx_win = mlx_new_window(data->win->mlx,
			(map->size_x) * 32, (map->size_y) * 32, "MARIO LT");
	return (data);
}
