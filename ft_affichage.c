#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_rendu *rendu, int y, int x, int color)
{
	char	*dst;

	dst = rendu->addr + (x * rendu->line_length + y * (rendu->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int    get_color_pixel(t_sprite *img, int y, int x)
{
    char    *src;
    int        color;

    src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    color = *(unsigned int *)src;
    return (color);
}

void	my_put(t_data *data,t_sprite *img,int x,int y)
{
	int j;
	int i;
	int color;

	j = 0;
	i = 0;
	while (j < img->img_height)
	{
		i = 0;
		while (i < img->img_width)
		{
			color =  get_color_pixel(img, j, i);
			if(color != 16711935 && (j+y < data->rendu->img_height && i+x < data->rendu->img_width))
				{
					my_mlx_pixel_put(data->rendu, i+x, j+y, color);
				}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->rendu->img, 0, 0);
	//printf("y = %d : %d\n",j+y ,data->rendu->img_height);
	//printf("x = %d : %d\n",i+x ,data->rendu->img_width);
	PRINTS("FIN");
}

void ft_clear_rendu(t_rendu *rendu)
{
	int j;
	int i;

	j = 0;
	while (rendu->img_height > j)
	{
		i = 0;
		while (rendu->img_width > i)
		{
			my_mlx_pixel_put(rendu, j, i, 0);
			i++;
		}
		j++;
	}
	
}


void	*ft_herbe_img(t_data *data,char **tab, int x, int y)
{

	static long int i;
	

	if(tab[y][x+1] && tab[y][x+1] == '0')
		my_put(data, data->herbeD, x*32, y*32);
	if(x > 0 && tab[y][x-1] == '0')
		my_put(data, data->herbeG, x*32, y*32);
	i++;
	if(i == 1)
		my_put(data, data->herbe1, x*32, y*32);
	if(i == 2)
		my_put(data, data->herbe2, x*32, y*32);
	if(i == 3)
		my_put(data, data->herbe3, x*32, y*32);
	if(i == 4)
	{
		i = 0;
		my_put(data, data->herbe4, x*32, y*32);
	}
	return(NULL);

}

void	*ft_terre_img(t_data *data,char **tab, int x, int y)
{

	static long int i;
	

	if(x != 0 && tab[y][x+1] && tab[y][x+1] != '1' )
		my_put(data, data->terreD, x*32, y*32);
	else if (x == 0 || (x > 0 && tab[y][x-1] != '1'))
		my_put(data, data->terreG, x*32, y*32);
	i++;
	if(i == 1)
		my_put(data, data->terre1, x*32, y*32);
	if(i == 2)
		my_put(data, data->terre2, x*32, y*32);
	if(i == 3)
		my_put(data, data->terre3, x*32, y*32);
	if(i == 4)
	{
		i = 0;
		my_put(data, data->terre4, x*32, y*32);
	}
	
	return(NULL);
}

int quit_game(int keycode, t_win *game)
{
	if (keycode == 65307)
	{
		printf("QUIT\n");
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	return (0);
}

t_win *ft_quite(void *mlx, void *mlx_win)
{
	t_win new;

	new.mlx = mlx;
	new.mlx_win = mlx_win;

	(void)new;
	return (NULL);
}

int nullfunc(t_win *new)
{
	(void)new;
	return 0;
}


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

int ft_affichage(char **tab, t_map *map)
{
	t_data 	*data;

	(void)tab;	

	int x;
	int y;

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
	data->rendu = malloc(sizeof(t_rendu));
	if (!data->rendu)
		return (0);
	data->rendu->img = mlx_new_image(data->win->mlx, (map->size_x)*32, (map->size_y)*32);
	data->rendu->addr = mlx_get_data_addr(data->rendu->img, &data->rendu->bits_per_pixel, &data->rendu->line_length, &data->rendu->endian);
	data->rendu->img_width = (map->size_x)*32;
	data->rendu->img_height = (map->size_y)*32;

	
	// A FINIR //
	/////////////////
	ft_init_all_sprite(data);
	ft_put_background_img(map, data);
	
	///////////////
	//printf("%p\n",&data->terre1->img_height);
	
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
			if(tab[y][x] == '2')
		   		my_put(data, data->blockP1, x*32, y*32);
			if(tab[y][x] == '3')
				my_put(data, data->blockB, x*32, y*32);
			//if(tab[y][x] == 'P')
				//mlx_put_image_to_window(mlx, mlx_win, img3, x*32, y*32-64);
			x++;
		}
		x = 0;
		y++;
	}
	

	//mlx_destroy_image(mlx, img->addr);
	//mlx_destroy_image(mlx, img2->addr);
	//mlx_destroy_window(mlx, mlx_win);

	//free(mlx);
	//free(mlx_win);
	//free(img);
	//free(img2);

	mlx_hook(data->win->mlx_win, KeyPress, KeyPressMask, quit_game, &data->rendu);
	mlx_loop_hook(data->win->mlx, nullfunc,  &data->rendu);
	mlx_loop(data->win->mlx);

	return(0);
}
