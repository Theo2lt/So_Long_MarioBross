#include "so_long.h"
#include "minilibx-linux/mlx.h"

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

t_data	*ft_return_herbe_img(t_data *imgs,char **tab, int x, int y)
{

	static long int i;
	

	if(tab[y][x+1] && tab[y][x+1] == '0')
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbeD.xpm"));
	if(x > 0 && tab[y][x-1] == '0')
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbeG.xpm"));
	i++;
	if(i == 1)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbe1.xpm"));
	if(i == 2)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbe2.xpm"));
	if(i == 3)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbe3.xpm"));
	if(i == 4)
	{
		i = 0;
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/herbe4.xpm"));
	}
	

}

t_data	*ft_return_terre_img(t_data *imgs,char **tab, int x, int y)
{

	static long int i;
	

	if(x != 0 && tab[y][x+1] && tab[y][x+1] != '1' )
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terreD.xpm"));
	else if (x == 0 || (x > 0 && tab[y][x-1] != '1'))
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terreG.xpm"));
	i++;
	if(i == 1)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terre1.xpm"));
	if(i == 2)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terre2.xpm"));
	if(i == 3)
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terre3.xpm"));
	if(i == 4)
	{
		i = 0;
		return(ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/terre4.xpm"));
	}
	

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


void	ft_put_background_img(t_map *data, t_data *imgs, void	*mlx,void	*mlx_win)
{
	t_data	*img_put;
	int y;
	int x;

	x = 0;
	img_put = ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/fond506.xpm");
	while(x < data->size_x*32)
	{
		mlx_put_image_to_window(mlx, mlx_win, img_put, x, (data->size_y*32)-img_put->img_height-32);
		x += img_put->img_width;
	}
	x = 0;
	y = (data->size_y*32)-(img_put->img_height*2);
	img_put = ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/fond506H.xpm");
	while(y > 0)
	{
		while(x < data->size_x*32)
		{
			mlx_put_image_to_window(mlx, mlx_win, img_put, x , y-32);
			x += img_put->img_width;
		}
		y -= img_put->img_height;
	}
	x = 0;
	while (y < 0 && x < data->size_x*32)
	{
		mlx_put_image_to_window(mlx, mlx_win, img_put, x, 0);
		x += img_put->img_width;
	}
}

void ft_affichage(char **tab, t_map *data)
{
	void	*mlx;
	void	*mlx_win;

	t_data 	*imgs;
	

	int x;
	int y;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, (data->size_x)*32, (data->size_y)*32, "CA MARCHE un peu!");

	/// POUR QUITER //
	t_win new;

	new.mlx = mlx;
	new.mlx_win = mlx_win;
	/////////////////

	imgs = ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/fond506.xpm");
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/fond506H.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbe1.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbe2.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbe3.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbe4.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbeD.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/herbeG.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terre1.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terre2.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terre3.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terre4.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terreD.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/terreG.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/blockP1.xpm"));
	ft_lstadd_back(imgs, ft_lstnew(mlx, mlx_win , "sprite/Sheet-XPM-32PX/block/blockB.xpm"));

	// A FINIR //
	ft_put_background_img(data, imgs, mlx,mlx_win);
	
	///////////////
	
	
	x = 0;
	y = 0;
	
	while(y < data->size_y)
	{
		while(x < data->size_x)
		{
			if(tab[y][x] == '1')
			{	
				if(y != data->size_y - 1 && (y == 0 || tab[y-1][x] == '1'))
					mlx_put_image_to_window(mlx, mlx_win, ft_return_terre_img(imgs,tab, x,  y), x*32, y*32);
				else
					mlx_put_image_to_window(mlx, mlx_win, ft_return_herbe_img(imgs,tab,x,y), x*32, y*32);
			}
			if(tab[y][x] == '2')
				mlx_put_image_to_window(mlx, mlx_win, ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/blockP1.xpm"), x*32, y*32);
			if(tab[y][x] == '3')
				mlx_put_image_to_window(mlx, mlx_win, ft_lst_cache_cache(imgs, "sprite/Sheet-XPM-32PX/block/blockB.xpm"), x*32, y*32);	
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

	mlx_hook(mlx_win, KeyPress, KeyPressMask, quit_game, &new);
	mlx_loop_hook(mlx, nullfunc, &new);
	mlx_loop(mlx);

}
