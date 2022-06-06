#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_img *rendu, int y, int x, int color)
{
	char	*dst;
	
	//printf("1ADD : %d\n",x * rendu->line_length);
	dst = rendu->addr + (x * rendu->line_length + y * (rendu->bits_per_pixel / 8));
	//printf("laa\n");
	if(dst)
		*(unsigned int*)dst = color;
	
}

unsigned int    get_color_pixel(t_img *img, int y, int x)
{
    char    *src;
    int        color;

    src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    color = *(unsigned int *)src;
    return (color);
}

void	my_put(t_img *rendu,t_img *img,int x,int y)
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
			if(color != 16711935 && (j+y > 0 && j+y < rendu->img_height && i+x > 0 && i+x < rendu->img_width))
				{
					my_mlx_pixel_put(rendu, i+x, j+y, color);
				}
			i++;
		}
		j++;
	}
}
