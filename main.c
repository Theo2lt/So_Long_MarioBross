#include "so_long.h"
#include "minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
			t_data;

void ft_affichage(char **tab, t_map *data)
{
	void	*mlx;
	void	*mlx_win;
	void 	*img;
	void 	*img2;
	char	*relative_path = "sprite/blo.xpm";
	char	*relative_path_fond = "sprite/SNES.xpm";

	int		img_width;
	int		img_height;

	int x;
	int y;



	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, (data->size_x-1)*64, (data->size_y)*64, "CA MARCHE un peu!");

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path_fond, &img_width, &img_height);

	mlx_put_image_to_window(mlx, mlx_win, img2, 0, 0);

	x = 0;
	y = 0;


	while(y < data->size_y)
	{
		while(x < data->size_x-1)
		{
			if(tab[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img, x*64, y*64);
			x++;
		}
		x = 0;
		y++;
	}


	mlx_loop(mlx);
}

int main(int argc, char **argv)
{
	char	**tab;
	t_map   *data;

	if(!ft_verif_arg(argc))
		return(0);
	tab = ft_create_tab(argv[1]);
	if(!tab)
		return (0);
	data = ft_lstnew(tab);
	if(!ft_verif_map_forme(tab, data) || !ft_verif_map_mur_y(tab, data) || !ft_verif_map_mur_x(tab, data) || !ft_verif_item(tab,data))
	{
		tab = ft_free(tab);
		free(data);
		return (0);
	}
	ft_affichage(tab,data);
	tab = ft_free(tab);
	free(data);
}

