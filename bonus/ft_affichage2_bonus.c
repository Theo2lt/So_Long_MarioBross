/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:48:01 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:03 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_herbe_img(t_data *data, char **tab, int x, int y)
{
	static long int	i;

	if (tab[y][x + 1] && tab[y][x + 1] == '0')
		my_put(data->rendu_mur, data->herbed, x * 32, y * 32);
	if (x > 0 && tab[y][x - 1] == '0')
		my_put(data->rendu_mur, data->herbeg, x * 32, y * 32);
	i++;
	if (i == 1)
		my_put(data->rendu_mur, data->herbe1, x * 32, y * 32);
	if (i == 2)
		my_put(data->rendu_mur, data->herbe2, x * 32, y * 32);
	if (i == 3)
		my_put(data->rendu_mur, data->herbe3, x * 32, y * 32);
	if (i == 4)
	{
		i = 0;
		my_put(data->rendu_mur, data->herbe4, x * 32, y * 32);
	}
	return (NULL);
}

void	*ft_terre_img(t_data *data, char **tab, int x, int y)
{
	static long int	i;

	if (x != 0 && tab[y][x + 1] && tab[y][x + 1] != '1' )
		my_put(data->rendu_mur, data->terred, x * 32, y * 32);
	else if (x == 0 || (x > 0 && tab[y][x - 1] != '1'))
		my_put(data->rendu_mur, data->terreg, x * 32, y * 32);
	i++;
	if (i == 1)
		my_put(data->rendu_mur, data->terre1, x * 32, y * 32);
	if (i == 2)
		my_put(data->rendu_mur, data->terre2, x * 32, y * 32);
	if (i == 3)
		my_put(data->rendu_mur, data->terre3, x * 32, y * 32);
	if (i == 4)
	{
		i = 0;
		my_put(data->rendu_mur, data->terre4, x * 32, y * 32);
	}
	return (NULL);
}

int	ft_intput_game(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_putstr("QUIT\n");
		mlx_loop_end(data->win->mlx);
	}
	else if (keycode == 119)
		ft_mouve_perso_haut(keycode, data->tab, data->map, data);
	else if (keycode == 115)
		ft_mouve_perso_bas(keycode, data->tab, data->map, data);
	else if (keycode == 97)
	{
		ft_mouve_perso_gauche(keycode, data->tab, data->map, data);
		data->perso->direction = -1;
	}
	else if (keycode == 100)
	{
		ft_mouve_perso_droite(keycode, data->tab, data->map, data);
		data->perso->direction = 1;
	}
	ft_mario_img(data, -1);
	ft_reset_rendu(data->tab, data->map, data);
	return (0);
}

void	ft_mario_img_sol2(t_data *data, long int sleep, int i)
{
	if (sleep != -1)
		data->mariotmp = data->mario_sd1;
	else if (i == 0)
		data->mariotmp = data->mario_sd1;
	else if (i == 1)
		data->mariotmp = data->mario_sd2;
	else if (i == 2)
		data->mariotmp = data->mario_sd3;
	else if (i == 3)
		data->mariotmp = data->mario_sd4;
}

void	ft_mario_img_sol(t_data *data, long int sleep)
{
	static int	i;

	if (data->perso->direction == 1)
		ft_mario_img_sol2(data, sleep, i);
	else
	{
		if (sleep != -1)
			data->mariotmp = data->mario_sg1;
		else if (i == 0)
			data->mariotmp = data->mario_sg1;
		else if (i == 1)
			data->mariotmp = data->mario_sg2;
		else if (i == 2)
			data->mariotmp = data->mario_sg3;
		else if (i == 3)
			data->mariotmp = data->mario_sg4;
	}
	if (i == 3)
		i = -1;
	i++;
}
