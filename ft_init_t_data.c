#include "so_long.h"

t_img *ft_new_sprite(t_data *data, char *path)
{
	t_img *img;
    int h;
    int w; 

	
	img = malloc(sizeof(t_img));
	if (img == NULL) 
	{
		printf("ERREUR : Malloc\n");
		return (NULL);
	}
	img = mlx_xpm_file_to_image(data->win->mlx,path, &w, &h);
	if (img == NULL) {
		printf("ERREUR : xpm_file_to_image\n");
		return (NULL);
	}
	img->img_height = h;
	img->img_width = w;
	img->addr = mlx_get_data_addr(img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->addr == NULL) 
	{
		printf("ERREUR : mlx_get_data_addr\n");
		return (NULL);
	}
	return (img);
}

void ft_init_all_sprite(t_data *data)
{
	data->piece1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece1.xpm");
	data->piece2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece2.xpm");
    data->piece3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece3.xpm");
    data->piece4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece4.xpm");
    data->fond506 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/fond/fond506.xpm");
	data->fond506H = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/fond/fond506H.xpm");
	data->herbe1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe1.xpm");
	data->herbe2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe2.xpm");
	data->herbe3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe3.xpm");
	data->herbe4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe4.xpm");
	data->herbeD = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbeD.xpm");
	data->herbeG = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbeG.xpm");	
	data->terre1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre1.xpm");	
	data->terre2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre2.xpm");	
	data->terre3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre3.xpm");
	data->terre4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre4.xpm");
	data->terreD = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terreD.xpm");	
	data->terreG = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terreG.xpm");	
	data->blockP1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockP1.xpm");	
	data->blockP2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockP2.xpm");
	data->blockP3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockP3.xpm");
	data->blockP4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockP4.xpm");
	data->blockB = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockB.xpm");
	data->mario = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/perso/mario.xpm");	
	data->SVH = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/SVH.xpm");	
	data->SRH = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/SRH.xpm");
}

t_data *ft_init_affichage(char **tab, t_map *map)
{
	t_data 	*data;

	(void)tab;
		// DATA //
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	// WIN //
	data->win = malloc(sizeof(t_win));
	if (!data->win)
		return (0);
	data->win->mlx = mlx_init();
	data->win->mlx_win = mlx_new_window(data->win->mlx, (map->size_x)*32, (map->size_y)*32, "Hello world!");
	//	RENDU //
	data->rendu = malloc(sizeof(t_img));
	if (!data->rendu)
		return (0);
	data->rendu->img = mlx_new_image(data->win->mlx, (map->size_x)*32, (map->size_y)*32);
	data->rendu->addr = mlx_get_data_addr(data->rendu->img, &data->rendu->bits_per_pixel, &data->rendu->line_length, &data->rendu->endian);
	data->rendu->img_width = (map->size_x)*32;
	data->rendu->img_height = (map->size_y)*32;
	//	RENDU //
	data->rendu_mur = malloc(sizeof(t_img));
	if (!data->rendu)
		return (0);
	data->rendu_mur->img = mlx_new_image(data->win->mlx, (map->size_x)*32, (map->size_y)*32);
	data->rendu_mur->addr = mlx_get_data_addr(data->rendu_mur->img, &data->rendu_mur->bits_per_pixel, &data->rendu_mur->line_length, &data->rendu_mur->endian);
	data->rendu_mur->img_width = (map->size_x)*32;
	data->rendu_mur->img_height = (map->size_y)*32;
	// INIT SPRITE //
	ft_init_all_sprite(data);
	// INIT PERSO //
	data->perso = malloc(sizeof(t_perso));
	data->perso->vie = 1;
	data->perso->deplacement = 0;
	return(data);
}

int ft_init_perso_position(char **tab, t_data *data)
{
		int x;
		int y;

		x = 0;
		y = 0;
		while(tab[y])
		{
			while(tab[y][x])
			{
				if(tab[y][x] == 'P')
				{
					data->perso->position_x = x;
					data->perso->position_y = y;
					data->perso->vie = 1;
					return(0);
				}
				x++;
			}
			x = 0;
			y++;
		}


	return(0);
}
