/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:28:27 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 16:24:42 by tliot            ###   ########.fr       */
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
		printf("ERREUR : xpm_file_to_image\n");
		ft_exit(data);
	}
	img->img_height = h;
	img->img_width = w;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
	{
		printf("ERREUR : mlx_get_data_addr\n");
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
		printf("ERREUR : Malloc\n");
		return (NULL);
	}
	img->img = NULL;
	img->addr = NULL;
	return (img);
}

void	ft_init_all_sprite(t_data *data)
{
	data->piece1 = ft_new_sprite();
	data->piece2 = ft_new_sprite();
	data->piece3 = ft_new_sprite();
	data->piece4 = ft_new_sprite();
	data->fond506 = ft_new_sprite();
	data->fond506H = ft_new_sprite();
	data->herbe1 = ft_new_sprite();
	data->herbe2 = ft_new_sprite();
	data->herbe3 = ft_new_sprite();
	data->herbe4 = ft_new_sprite();
	data->herbeD = ft_new_sprite();
	data->herbeG = ft_new_sprite();
	data->terre1 = ft_new_sprite();
	data->terre2 = ft_new_sprite();
	data->terre3 = ft_new_sprite();
	data->terre4 = ft_new_sprite();
	data->terreD = ft_new_sprite();
	data->terreG = ft_new_sprite();
	data->blockP1 = ft_new_sprite();
	data->blockP2 = ft_new_sprite();
	data->blockP3 = ft_new_sprite();
	data->blockP4 = ft_new_sprite();
	data->blockB = ft_new_sprite();
	data->SVH = ft_new_sprite();
	data->SRH = ft_new_sprite();
	data->Piranha1 = ft_new_sprite();
	data->Piranha2 = ft_new_sprite();
	data->Piranha3 = ft_new_sprite();
	data->Piranha4 = ft_new_sprite();
	data->Piranha5 = ft_new_sprite();
	data->Piranha6 = ft_new_sprite();
	data->mario_HD1 = ft_new_sprite();
	data->mario_HD2 = ft_new_sprite();
	data->mario_HD3 = ft_new_sprite();
	data->mario_HG1 = ft_new_sprite();
	data->mario_HG2 = ft_new_sprite();
	data->mario_HG3 = ft_new_sprite();
	data->mario_init1 = ft_new_sprite();
	data->mario_init2 = ft_new_sprite();
	data->mario_SD1 = ft_new_sprite();
	data->mario_SD2 = ft_new_sprite();
	data->mario_SD3 = ft_new_sprite();
	data->mario_SD4 = ft_new_sprite();
	data->mario_SG1 = ft_new_sprite();
	data->mario_SG2 = ft_new_sprite();
	data->mario_SG3 = ft_new_sprite();
	data->mario_SG4 = ft_new_sprite();
}


void ft_init_all_img_addr(t_data *data)
{
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/piece/piece1.xpm",data->piece1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/piece/piece2.xpm",data->piece2);
    ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/piece/piece3.xpm",data->piece3);
    ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/piece/piece4.xpm",data->piece4);
    ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/fond/fond506.xpm",data->fond506);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/fond/fond506H.xpm",data->fond506H);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbe1.xpm",data->herbe1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbe2.xpm",data->herbe2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbe3.xpm",data->herbe3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbe4.xpm",data->herbe4);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbeD.xpm",data->herbeD);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/herbeG.xpm",data->herbeG);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terre1.xpm",data->terre1);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terre2.xpm",data->terre2);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terre3.xpm",data->terre3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terre4.xpm",data->terre4);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terreD.xpm",data->terreD);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/terreG.xpm",data->terreG);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/blockP1.xpm",data->blockP1);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/blockP2.xpm",data->blockP2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/blockP3.xpm",data->blockP3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/blockP4.xpm",data->blockP4);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/blockB.xpm",data->blockB );
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/SVH.xpm",data->SVH);	
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/block/SRH.xpm",data->SRH);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha1.xpm",data->Piranha1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha2.xpm",data->Piranha2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha3.xpm",data->Piranha3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha4.xpm",data->Piranha4);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha5.xpm",data->Piranha5);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/Piranha6.xpm",data->Piranha6);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HD1.xpm",data->mario_HD1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HD2.xpm",data->mario_HD2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HD3.xpm",data->mario_HD3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HG1.xpm",data->mario_HG1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HG2.xpm",data->mario_HG2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_HG3.xpm",data->mario_HG3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_init1.xpm",data->mario_init1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_init2.xpm",data->mario_init2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SD1.xpm",data->mario_SD1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SD2.xpm",data->mario_SD2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SD3.xpm",data->mario_SD3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SD4.xpm",data->mario_SD4);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SG1.xpm",data->mario_SG1);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SG2.xpm",data->mario_SG2);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SG3.xpm",data->mario_SG3);
	ft_new_img_addr(data, "sprite/Sheet-XPM-32PX-transparency/perso/mario_SG4.xpm",data->mario_SG4);

}


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
	data->perso->vie = 1;
	data->perso->deplacement = 0;
	data->tab = tab;
	data->map = map;
	ft_init_all_sprite(data);
	ft_init_all_img_addr(data);
	data->troupe_piranha = NULL;
	ft_init_piranha_position(tab, data);
	return (data);
}

int ft_init_perso_position(char **tab, t_data *data)
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


int ft_init_piranha_position(char **tab, t_data *data)
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
