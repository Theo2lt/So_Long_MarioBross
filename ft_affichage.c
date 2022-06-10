/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:01:11 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 18:25:26 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_null_sleep1(t_data *data, long int sleep)
{
	if (sleep == 0)
	{	
		ft_piranha_img(data);
		data->piecetmp = data->piece1;
		data->blockptmp = data->blockp1;
		ft_reset_rendu(data->tab, data->map, data);
	}
	if (sleep == 200000)
	{
		data->piecetmp = data->piece2;
		data->blockptmp = data->blockp2;
		ft_reset_rendu(data->tab, data->map, data);
	}	
}

void	ft_null_sleep2(t_data *data, long int sleep)
{
	if (sleep == 400000)
	{
		ft_piranha_img(data);
		data->piecetmp = data->piece3;
		data->blockptmp = data->blockp3;
		ft_reset_rendu(data->tab, data->map, data);
	}
	if (sleep == 600000)
	{
		data->piecetmp = data->piece4;
		data->blockptmp = data->blockp4;
		ft_reset_rendu(data->tab, data->map, data);
	}
}

int	nullfunc(t_data *data)
{
	long int		time_sleep;
	static long int	sleep;

	time_sleep = 5000;
	ft_mario_img(data, sleep);
	ft_null_sleep1(data, sleep);
	ft_null_sleep2(data, sleep);
	if (sleep == 600000)
		sleep = -time_sleep;
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win,
		data->rendu->img, 0, 0);
	ft_my_mlx_string_put(data);
	usleep(time_sleep);
	sleep += time_sleep;
	return (0);
}

int	exit_hook(t_data *data)
{
	(void) data;
	mlx_loop_end(data->win->mlx);
	return (0);
}

int	ft_affichage(t_data *data)
{
	mlx_do_key_autorepeatoff(data->win->mlx);
	ft_init_rendu_mur(data->tab, data->map, data);
	mlx_hook(data->win->mlx_win, KeyPress, KeyPressMask, ft_intput_game, data);
	mlx_hook(data->win->mlx_win, 17, (1L << 17), &exit_hook, data);
	mlx_loop_hook(data->win->mlx, nullfunc, data);
	mlx_loop(data->win->mlx);
	ft_exit(data);
	return (0);
}
