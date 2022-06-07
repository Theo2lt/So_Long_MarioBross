#include "so_long.h"
#include "minilibx-linux/mlx.h"


void	*ft_herbe_img(t_data *data,char **tab, int x, int y)
{

	static long int i;
	

	if(tab[y][x+1] && tab[y][x+1] == '0')
		my_put(data->rendu_mur, data->herbeD, x*32, y*32);
	if(x > 0 && tab[y][x-1] == '0')
		my_put(data->rendu_mur, data->herbeG, x*32, y*32);
	i++;
	if(i == 1)
		my_put(data->rendu_mur, data->herbe1, x*32, y*32);
	if(i == 2)
		my_put(data->rendu_mur, data->herbe2, x*32, y*32);
	if(i == 3)
		my_put(data->rendu_mur, data->herbe3, x*32, y*32);
	if(i == 4)
	{
		i = 0;
		my_put(data->rendu_mur, data->herbe4, x*32, y*32);
	}
	return(NULL);

}

void	*ft_terre_img(t_data *data,char **tab, int x, int y)
{

	static long int i;
	

	if(x != 0 && tab[y][x+1] && tab[y][x+1] != '1' )
		my_put(data->rendu_mur, data->terreD, x*32, y*32);
	else if (x == 0 || (x > 0 && tab[y][x-1] != '1'))
		my_put(data->rendu_mur, data->terreG, x*32, y*32);
	i++;
	if(i == 1)
		my_put(data->rendu_mur, data->terre1, x*32, y*32);
	if(i == 2)
		my_put(data->rendu_mur, data->terre2, x*32, y*32);
	if(i == 3)
		my_put(data->rendu_mur, data->terre3, x*32, y*32);
	if(i == 4)
	{
		i = 0;
		my_put(data->rendu_mur, data->terre4, x*32, y*32);
	}
	
	return(NULL);
}

int ft_intput_game(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		printf("QUIT\n");
		mlx_loop_end(data->win->mlx);

	}
	else if(keycode == 119)
	{	
		ft_mouve_perso_haut(keycode ,data->tab, data->map, data);
		data->perso->deplacement++;
	}
	else if (keycode == 115)
	{
		ft_mouve_perso_bas(keycode ,data->tab, data->map, data);
		data->perso->deplacement++;
	}
	else if (keycode == 97)
	{
		ft_mouve_perso_gauche(keycode ,data->tab, data->map, data);
		data->perso->direction = -1;
		data->perso->deplacement++;
	}
	else if (keycode == 100)
	{
		ft_mouve_perso_droite(keycode ,data->tab, data->map, data);
		data->perso->direction = 1;
		data->perso->deplacement++;
	}
	ft_mario_img(data,-1);
	ft_reset_rendu(data->tab, data->map, data);
	return (0);
}

void ft_mario_img_sol(t_data *data, long int sleep)
{
	static int i;
	if(data->perso->direction == 1)
	{	
		if(sleep != -1)
			data->mariotmp = data->mario_SD1;
		else if(i == 0)
			data->mariotmp = data->mario_SD1;
		else if(i == 1)
			data->mariotmp = data->mario_SD2;
		else if(i == 2)
			data->mariotmp = data->mario_SD3;
		else if(i == 3)
			data->mariotmp = data->mario_SD4;
	}
	else
	{
		if(sleep != -1)
			data->mariotmp = data->mario_SG1;
		else if(i == 0)
			data->mariotmp = data->mario_SG1;
		else if(i == 1)
			data->mariotmp = data->mario_SG2;
		else if(i == 2)
			data->mariotmp = data->mario_SG3;
		else if(i == 3)
			data->mariotmp = data->mario_SG4;
	}
	if(i == 3)
		i = -1;
	i++;
}

void ft_mario_img_haut(t_data *data,long int sleep)
{
	if(data->perso->direction == 1)
	{
		if(sleep == 0)
			data->mariotmp = data->mario_HD1;
		else if(sleep == 200000)
			data->mariotmp = data->mario_HD2;
		else if(sleep == 400000)
			data->mariotmp = data->mario_HD3;
		else if(sleep == 600000)
			data->mariotmp = data->mario_HD2;
	}
	else
	{
		if(sleep == 0)
			data->mariotmp = data->mario_HG1;
		else if(sleep == 200000)
			data->mariotmp = data->mario_HG2;
		else if(sleep == 400000)
			data->mariotmp = data->mario_HG3;
		else if(sleep == 600000)
			data->mariotmp = data->mario_HG2;
	}
}


void ft_mario_img(t_data *data,long int sleep)
{
	int y;
	int x;

	y = data->perso->position_y;
	x = data->perso->position_x;
	
	if(data->perso->deplacement == 0 || data->tab[y+1][x] == 'E')
	{
		if(sleep == 0)
			data->mariotmp = data->mario_init1;
		else if(sleep == 200000)
			data->mariotmp = data->mario_init2;
	}
	else
	{
		if(data->tab[y+1][x] == '1' ||  data->tab[y+1][x] == '2' || data->tab[y+1][x] == '3')
			ft_mario_img_sol(data,sleep);
		else
			ft_mario_img_haut(data,sleep);
	}
}

int nullfunc(t_data *data)
{
	long int time_sleep;
	static long int sleep;
	time_sleep = 5000;

	ft_mario_img(data,sleep);
	if(sleep == 0)
	{	
		data->piecetmp = data->piece1;
		data->blockPtmp = data->blockP1;
		ft_reset_rendu(data->tab, data->map, data);

	}

	if(sleep == 200000)
	{
		data->piecetmp = data->piece2;
		data->blockPtmp = data->blockP2;
		ft_reset_rendu(data->tab, data->map, data);
	}	
	if(sleep == 400000)
	{
		data->piecetmp = data->piece3;
		data->blockPtmp = data->blockP3;
		ft_reset_rendu(data->tab, data->map, data);
	}
	if(sleep == 600000)
	{
		data->piecetmp = data->piece4;
		data->blockPtmp = data->blockP4;
		ft_reset_rendu(data->tab, data->map, data);
		sleep = -time_sleep;
	}
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->rendu->img, 0, 0);
	ft_my_mlx_string_put(data);
	usleep(time_sleep);
	sleep+= time_sleep;
	return 0;
}

/*
void	ft_put_background_img(t_map *map, t_data *data)
{
	int y;
	int x;

	x = 0;
	while(x < map->size_x*32)
	{
		y = (map->size_y*32)-data->fond506->img_height-32;
		my_put(data, data->fond506, x, y);
		x += data->fond506->img_width;
	}
	x = 0;
	y = (map->size_y*32)-(data->fond506H->img_height*2);
	while(y > 0)
	{
		while(x < map->size_x*32)
		{
			my_put(data, data->fond506H, x , y-32);
			x += data->fond506H->img_width;
		}
		y += data->fond506H->img_height;
	}
	x = 0;
	while (y < 0 && x < map->size_x*32)
	{
		my_put(data, data->fond506H, x, 0);
		x += data->fond506H->img_width;
	}
}
*/

void 	ft_put_background_img(t_map *map, t_data *data)
{
	int y;
	int x;

	y = 0;
	x = 0;

	
	while (x < map->size_x*32)
	{
		my_put(data->rendu_mur, data->fond506, x, map->size_y*32-data->fond506->img_height);
		y = map->size_y*32-(2*data->fond506->img_height);
		while (y > -data->fond506H->img_height)
		{
			my_put(data->rendu_mur, data->fond506H, x, y);
			y += -data->fond506H->img_height;
		}
		x += data->fond506->img_height;
	}

}




void ft_init_rendu_mur(char **tab, t_map *map, t_data *data)
{
	int x;
	int y;
	
	ft_put_background_img(map, data);

	x = 0;
	y = 0; 
	while(y < map->size_y)
	{
		while(x < map->size_x)
		{
			if(tab[y][x] == '1')
			{	
				if(y != map->size_y - 1 && (y == 0 || tab[y-1][x] == '1'))
					ft_terre_img(data ,tab,x, y);
				else
					ft_herbe_img(data ,tab,x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}	
}

void ft_reset_rendu(char **tab, t_map *map, t_data *data)
{
	int x;
	int y;
	
	my_put(data->rendu, data->rendu_mur, 0, 0);
	x = 0;
	y = 0; 
	while(y < map->size_y)
	{
		while(x < map->size_x)
		{
			if(tab[y][x] == '2')
		   		my_put(data->rendu, data->blockPtmp, x*32, y*32);
			if(tab[y][x] == '3')
				my_put(data->rendu, data->blockB, x*32, y*32);
			if(tab[y][x] == 'C')
				my_put(data->rendu, data->piecetmp, x*32, y*32);
			if(tab[y][x] == 'P')
				my_put(data->rendu, data->mariotmp, x*32, y*32);
			if(tab[y][x] == 'E')
			{	
				if(data->map->nbr_C == 0)
					my_put(data->rendu, data->SVH, x*32, y*32);
				else
					my_put(data->rendu, data->SRH, x*32, y*32);
			}
			x++;
		}
		x = 0;
		y++;
	}

}

int ft_affichage(t_data *data)
{
	mlx_do_key_autorepeatoff(data->win->mlx);	
	ft_init_rendu_mur(data->tab, data->map, data);
	mlx_hook(data->win->mlx_win, KeyPress, KeyPressMask, ft_intput_game, data);
	mlx_loop_hook(data->win->mlx, nullfunc,  data);
	mlx_loop(data->win->mlx);
	ft_exit(data);
	return (0);
}
