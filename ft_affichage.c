#include "so_long.h"
#include "minilibx-linux/mlx.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} t_data;

void ft_affichage(char **tab, t_map *data)
{
	void	*mlx;
	void	*mlx_win;
	t_data 	*img;
	t_data 	*img2;
	t_data 	*img3;
	char	*relative_path = "sprite/blo.xpm";
	char	*relative_path_fond = "sprite/wallpaper.xpm";
	char	*relative_path_doors= "sprite/fort192(fond-transparent).xpm";

	int		img_width;
	int		img_height;

	int x;
	int y;



	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, (data->size_x-1)*64, (data->size_y)*64, "CA MARCHE un peu!");



	img2 = mlx_xpm_file_to_image(mlx, relative_path_fond, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img2, 0, (data->size_y)*64-img_height - 64);

	img3 = mlx_xpm_file_to_image(mlx, relative_path_doors, &img_width, &img_height);

	x = 0;
	y = 0;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while(y < data->size_y)
	{
		while(x < data->size_x-1)
		{
			if(tab[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img, x*64, y*64);
			if(tab[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img3, x*64, y*64-128);
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
