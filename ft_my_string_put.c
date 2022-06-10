/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_string_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:39:23 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 17:40:14 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_my_mlx_string_put(t_data *data)
{
	char	*str;

	str = ft_itoa(data->perso->deplacement);
	mlx_string_put(data->win->mlx, data->win->mlx_win, 40, 50, 0xFFFFFF, str);
	free(str);
}
