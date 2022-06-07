#include "so_long.h"
void ft_free_img(t_img *img,t_data *data)
{
	if(img)
	{
		mlx_destroy_image(data->win->mlx, img->img);
		free(img);
	}
}


void ft_free_affichage(t_data *data)
{
	ft_free_img(data->piece1, data);
	ft_free_img(data->piece2, data);
	ft_free_img(data->piece3, data);
	ft_free_img(data->piece4, data);
	ft_free_img(data->fond506, data);
	ft_free_img(data->fond506H, data);
	ft_free_img(data->herbe1, data);
	ft_free_img(data->herbe2, data);
	ft_free_img(data->herbe3, data);
	ft_free_img(data->herbe4, data);
	ft_free_img(data->herbeD, data);
	ft_free_img(data->herbeG, data);
	ft_free_img(data->terre1, data);
	ft_free_img(data->terre2, data);
	ft_free_img(data->terre3, data);
	ft_free_img(data->terre4, data);
	ft_free_img(data->terreD, data);
	ft_free_img(data->terreG, data);
	ft_free_img(data->blockP1, data);
	ft_free_img(data->blockP2, data);
	ft_free_img(data->blockP3, data);
	ft_free_img(data->blockP4, data);
	ft_free_img(data->blockB, data);
	ft_free_img(data->SVH, data);
	ft_free_img(data->SRH, data);

	ft_free_img(data->monstre, data);
	ft_free_img(data->monstre2, data);
	ft_free_img(data->monstreR, data);
	ft_free_img(data->monstreR2, data);


	ft_free_img(data->mario_HD1, data);
	ft_free_img(data->mario_HD2, data);
	ft_free_img(data->mario_HD3, data);
	ft_free_img(data->mario_HG1, data);
	ft_free_img(data->mario_HG2, data);
	ft_free_img(data->mario_HG3, data);
	ft_free_img(data->mario_init1, data);
	ft_free_img(data->mario_init2, data);
	ft_free_img(data->mario_SD1, data);
	ft_free_img(data->mario_SD2, data);
	ft_free_img(data->mario_SD3, data);
	ft_free_img(data->mario_SD4, data);
	ft_free_img(data->mario_SG1, data);
	ft_free_img(data->mario_SG2, data);
	ft_free_img(data->mario_SG3, data);
	ft_free_img(data->mario_SG4, data);
	
	mlx_destroy_image(data->win->mlx, data->rendu->img);
	mlx_destroy_image(data->win->mlx, data->rendu_mur->img);
	mlx_clear_window(data->win->mlx, data->win->mlx_win);
	mlx_destroy_window(data->win->mlx, data->win->mlx_win);
	mlx_destroy_display(data->win->mlx);
}

void ft_free_data(t_data *data)
{
		if(data->win->mlx)
			free(data->win->mlx);
		if(data->perso)
			free(data->perso);
		if(data->rendu_mur)
			free(data->rendu_mur);
		if(data->rendu)
			free(data->rendu);
		if(data->win)
			free(data->win);
		if(data->tab)
			data->tab = ft_free(data->tab);
		if(data->map)
			free(data->map);
		if(data)
			free(data);		

}

void ft_exit(t_data *data)
{		
		if(data)
		{
			ft_free_affichage(data);
			ft_free_data(data);
		}

		exit(0);
}