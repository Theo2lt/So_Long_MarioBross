#include "so_long.h"
void ft_free_img(t_img *img,t_data *data)
{
	static int i;
	if(img)
	{
		printf("data->win->mlx : %p\n",data->win->mlx);
		printf("		   img : %s\n",(char *)img->img);
		//mlx_destroy_image(data->win->mlx, img->img);
		free(img);
		printf("%d\n",i);
		i++;
	}
}


void ft_exit(t_data *data)
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
		ft_free_img(data->mario, data);
		ft_free_img(data->SVH, data);
		ft_free_img(data->SRH, data);
	

		mlx_destroy_image(data->win->mlx, data->rendu->img);
		mlx_destroy_image(data->win->mlx, data->rendu_mur->img);
		mlx_clear_window(data->win->mlx, data->win->mlx_win);
		mlx_destroy_window(data->win->mlx, data->win->mlx_win);
		mlx_destroy_display(data->win->mlx);




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
		//mlx_destroy_image(data->win->mlx, data->piece1->img);
		
		

		
		exit(0);
}