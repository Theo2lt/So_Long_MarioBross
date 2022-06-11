/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:17:39 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 19:21:19 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_img(t_img *img, t_data *data)
{
	if (img)
	{	
		if (img->img)
			mlx_destroy_image(data->win->mlx, img->img);
		free(img);
	}
}

void	ft_free_sprite(t_data *data)
{
	ft_free_img(data->piece1, data);
	ft_free_img(data->piece2, data);
	ft_free_img(data->piece3, data);
	ft_free_img(data->piece4, data);
	ft_free_img(data->herbe1, data);
	ft_free_img(data->herbe2, data);
	ft_free_img(data->herbe3, data);
	ft_free_img(data->herbe4, data);
	ft_free_img(data->herbed, data);
	ft_free_img(data->herbeg, data);
	ft_free_img(data->terre1, data);
	ft_free_img(data->terre2, data);
	ft_free_img(data->terre3, data);
	ft_free_img(data->terre4, data);
	ft_free_img(data->terred, data);
	ft_free_img(data->terreg, data);
	ft_free_img(data->blockp1, data);
	ft_free_img(data->blockp2, data);
	ft_free_img(data->blockp3, data);
	ft_free_img(data->blockp4, data);
	ft_free_img(data->blockb, data);
	ft_free_img(data->svh, data);
	ft_free_img(data->srh, data);
}

void	ft_free_sprite_piranha(t_data *data)
{
	ft_free_img(data->fond506, data);
	ft_free_img(data->fond506h, data);
	ft_free_img(data->piranha1, data);
	ft_free_img(data->piranha2, data);
	ft_free_img(data->piranha3, data);
	ft_free_img(data->piranha4, data);
	ft_free_img(data->piranha5, data);
	ft_free_img(data->piranha6, data);
}

void	ft_free_affichage(t_data *data)
{
	ft_free_sprite(data);
	ft_free_sprite_piranha(data);
	ft_free_img(data->mario_hd1, data);
	ft_free_img(data->mario_hd2, data);
	ft_free_img(data->mario_hd3, data);
	ft_free_img(data->mario_hg1, data);
	ft_free_img(data->mario_hg2, data);
	ft_free_img(data->mario_hg3, data);
	ft_free_img(data->mario_init1, data);
	ft_free_img(data->mario_init2, data);
	ft_free_img(data->mario_sd1, data);
	ft_free_img(data->mario_sd2, data);
	ft_free_img(data->mario_sd3, data);
	ft_free_img(data->mario_sd4, data);
	ft_free_img(data->mario_sg1, data);
	ft_free_img(data->mario_sg2, data);
	ft_free_img(data->mario_sg3, data);
	ft_free_img(data->mario_sg4, data);
	mlx_destroy_image(data->win->mlx, data->rendu->img);
	mlx_destroy_image(data->win->mlx, data->rendu_mur->img);
	mlx_clear_window(data->win->mlx, data->win->mlx_win);
	mlx_destroy_window(data->win->mlx, data->win->mlx_win);
	mlx_destroy_display(data->win->mlx);
}

void	ft_exit(t_data *data)
{
	if (data)
	{
		ft_free_affichage(data);
		ft_free_data(data);
	}
	exit(0);
}
