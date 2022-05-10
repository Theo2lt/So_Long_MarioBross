#include "so_long.h"
#include "minilibx-linux/mlx.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} t_data;


void ft_put_affiche_herbe(void	*mlx, void	*mlx_win ,int x, int y)
{

	static long int i;
	i++;

	t_data *herbe1;
	t_data *herbe2;
	t_data *herbe3;
	t_data *herbe4;
	t_data *herbeD;
	t_data *herbeG;

	int		img_width;
	int		img_height;
	
	herbe1 = mlx_xpm_file_to_image(mlx,"sprite/Sheet-XPM-32PX/block/herbe1.xpm", &img_width, &img_height);
	herbe2 = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/herbe2.xpm", &img_width, &img_height);
	herbe3 = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/herbe3.xpm", &img_width, &img_height);
	herbe4 = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/herbe4.xpm", &img_width, &img_height);
	herbeD = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/herbeD.xpm", &img_width, &img_height);
	herbeG = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/herbeG.xpm", &img_width, &img_height);

	if(!mlx)
		printf("mlx NULL\n");
	if(!mlx_win)
		printf("mlx_win NULL \n");
	if(i == 1)
		mlx_put_image_to_window(mlx, mlx_win, herbe1, x, y);
	if(i == 2)
		mlx_put_image_to_window(mlx, mlx_win, herbe2, x, y);
	if(i == 3)
		mlx_put_image_to_window(mlx, mlx_win, herbe3, x, y);
	if(i == 4)
		mlx_put_image_to_window(mlx, mlx_win, herbe4, x, y);
	if(i == 4)
		i = 0;
}



void ft_affichage(char **tab, t_map *data)
{
	void	*mlx;
	void	*mlx_win;

	t_data 	*img2;
	t_data 	*img3;
	t_data	*terre;

	int		img_width;
	int		img_height;

	int x;
	int y;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, (data->size_x-1)*32, (data->size_y)*32, "CA MARCHE un peu!");



	img2 = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/fond506.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img2, 0, (data->size_y)*32-img_height - 32);

	//img3 = mlx_xpm_file_to_image(mlx, "sprite/fort192(fond-transparent).xpm", &img_width, &img_height);
	
	terre = mlx_xpm_file_to_image(mlx, "sprite/Sheet-XPM-32PX/block/terre1.xpm", &img_width, &img_height);

	x = 0;
	y = 0;

	while(y < data->size_y)
	{
		while(x < data->size_x-1)
		{
			if(tab[y][x] == '1')
			{	
				if(y == 0 || tab[y-1][x] == '1')
					mlx_put_image_to_window(mlx, mlx_win, terre, x*32, y*32);
				else
					ft_put_affiche_herbe(mlx, mlx_win, x*32, y*32);
			}
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
	mlx_loop(mlx);
}
