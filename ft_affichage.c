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
	static long int i;
	if (keycode == 65307)
	{
		printf("QUIT\n");
		//mlx_destroy_window(data->win->mlx, data->win->mlx);
	}
	else if(keycode == 119)
	{	
		ft_mouve_perso_haut(keycode ,data->tab, data->map, data);
		i++;
	}
	else if (keycode == 115)
	{
		ft_mouve_perso_bas(keycode ,data->tab, data->map, data);
		i++;
	}
	else if (keycode == 97)
	{
		ft_mouve_perso_gauche(keycode ,data->tab, data->map, data);
		i++;
	}
	else if (keycode == 100)
	{
		ft_mouve_perso_droite(keycode ,data->tab, data->map, data);
		i++;
	}
	ft_reset_rendu(data->tab, data->map, data);
	
	//printf("tab[%d][%d]\n", data->perso->position_y, data->perso->position_x);
	printf("Nombre de coup : %ld\n",i);
	//printf("Keycode : %d\n",keycode);

	//printf("---- MAP ---\n");
	/*
	int x = 0;
	int y = 0;
	while(data->tab[y])
	{
		while(data->tab[y][x])
		{
			printf("%c",data->tab[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	*/
	//printf("Nombre de piece : %d\n", data->map->nbr_C);
	return (0);
}


int nullfunc(t_data *data)
{
	long int time_sleep;
	static long int sleep;
	time_sleep = 5000;


	if(sleep == 0)
	{
		data->piecetmp = data->piece1;
		ft_reset_rendu(data->tab, data->map, data);
	}

	if(sleep == 300000)
	{
		data->piecetmp = data->piece2;
		ft_reset_rendu(data->tab, data->map, data);
		
	}	
	if(sleep == 600000)
	{
		data->piecetmp = data->piece3;
		ft_reset_rendu(data->tab, data->map, data);
	}
	if(sleep == 900000)
	{
		data->piecetmp = data->piece4;
		ft_reset_rendu(data->tab, data->map, data);
		sleep = -time_sleep;
	}
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->rendu->img, 0, 0);
	usleep(time_sleep);
	sleep+= time_sleep;

	//printf("sleep : %ld\n",sleep);
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




void ft_init_rendu_mur(char **tab, t_map *map, t_data *data)
{
	int x;
	int y;
	
	//ft_put_background_img(map, data);
	ft_clear_rendu(data->rendu_mur);

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
	
	//ft_put_background_img(map, data);
	my_put(data->rendu, data->rendu_mur, 0, 0);
	x = 0;
	y = 0; 
	while(y < map->size_y)
	{
		while(x < map->size_x)
		{
			if(tab[y][x] == '2')
		   		my_put(data->rendu, data->blockP1, x*32, y*32);
			if(tab[y][x] == '3')
				my_put(data->rendu, data->blockB, x*32, y*32);
			if(tab[y][x] == 'C')
				my_put(data->rendu, data->piecetmp, x*32, y*32);
			if(tab[y][x] == 'P')
				my_put(data->rendu, data->mario, x*32, y*32);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->rendu->img, 0, 0);

}

int ft_affichage(t_data *data)
{	
	ft_init_rendu_mur(data->tab, data->map, data);
	mlx_hook(data->win->mlx_win, KeyPress, KeyPressMask, ft_intput_game, data);
	mlx_loop_hook(data->win->mlx, nullfunc,  data);
	printf("LAAAA\n");
	mlx_loop(data->win->mlx);
	return(0);
}
