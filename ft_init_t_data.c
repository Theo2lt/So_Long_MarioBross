/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:28:27 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 19:29:29 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_img_addr(t_data *data, char *path, t_img *img)
{
	int	h;
	int	w;

	img->img = mlx_xpm_file_to_image(data->win->mlx, path, &w, &h);
	if (img->img == NULL)
	{
		ft_putstr("ERREUR : xpm_file_to_image\n");
		ft_exit(data);
	}
	img->img_height = h;
	img->img_width = w;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
	{
		ft_putstr("ERREUR : mlx_get_data_addr\n");
		ft_exit(data);
	}
}

t_img	*ft_new_sprite(void)
{
	t_img	*img;

	img = NULL;
	img = malloc(sizeof(t_img));
	if (img == NULL)
	{
		ft_putstr("ERREUR : Malloc\n");
		return (NULL);
	}
	img->img = NULL;
	img->addr = NULL;
	return (img);
}

void	ft_init_all_sprite2(t_data *data)
{
	data->piece1 = ft_new_sprite();
	data->piece2 = ft_new_sprite();
	data->piece3 = ft_new_sprite();
	data->piece4 = ft_new_sprite();
	data->fond506 = ft_new_sprite();
	data->fond506h = ft_new_sprite();
	data->herbe1 = ft_new_sprite();
	data->herbe2 = ft_new_sprite();
	data->herbe3 = ft_new_sprite();
	data->herbe4 = ft_new_sprite();
	data->herbed = ft_new_sprite();
	data->herbeg = ft_new_sprite();
	data->terre1 = ft_new_sprite();
	data->terre2 = ft_new_sprite();
	data->terre3 = ft_new_sprite();
	data->terre4 = ft_new_sprite();
	data->terred = ft_new_sprite();
	data->terreg = ft_new_sprite();
	data->blockp1 = ft_new_sprite();
	data->blockp2 = ft_new_sprite();
	data->blockp3 = ft_new_sprite();
	data->blockp4 = ft_new_sprite();
	data->blockb = ft_new_sprite();
	data->svh = ft_new_sprite();
	data->srh = ft_new_sprite();
}

void	ft_init_all_sprite(t_data *data)
{
	ft_init_all_sprite2(data);
	data->piranha1 = ft_new_sprite();
	data->piranha2 = ft_new_sprite();
	data->piranha3 = ft_new_sprite();
	data->piranha4 = ft_new_sprite();
	data->piranha5 = ft_new_sprite();
	data->piranha6 = ft_new_sprite();
	data->mario_hd1 = ft_new_sprite();
	data->mario_hd2 = ft_new_sprite();
	data->mario_hd3 = ft_new_sprite();
	data->mario_hg1 = ft_new_sprite();
	data->mario_hg2 = ft_new_sprite();
	data->mario_hg3 = ft_new_sprite();
	data->mario_init1 = ft_new_sprite();
	data->mario_init2 = ft_new_sprite();
	data->mario_sd1 = ft_new_sprite();
	data->mario_sd2 = ft_new_sprite();
	data->mario_sd3 = ft_new_sprite();
	data->mario_sd4 = ft_new_sprite();
	data->mario_sg1 = ft_new_sprite();
	data->mario_sg2 = ft_new_sprite();
	data->mario_sg3 = ft_new_sprite();
	data->mario_sg4 = ft_new_sprite();
}
