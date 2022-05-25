#include "so_long.h"

t_sprite *ft_new_sprite(t_data *data, char *path)
{
	t_sprite *img;
    int h;
    int w; 
	//img = malloc(sizeof(t_sprite));
	// if (!img) {
	// 	PRINTS("COUCOU3")

	// 	return (NULL);
	// }
	img = mlx_xpm_file_to_image(data->win->mlx,path, &w, &h);
	if (img == NULL) {
		PRINTS("COUCOU2")

		return (NULL);
	}
	img->img_height = h;
	img->img_width = w;
	img->addr = mlx_get_data_addr(img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->addr == NULL) {

		PRINTS("COUCOU")
		return (NULL);
	}
	
	
	return (img);
}

void ft_init_all_sprite(t_data *data)
{
    data->piece1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece1.xpm");
    data->piece2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece2.xpm");
    data->piece3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece3.xpm");
    data->piece4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/piece/piece4.xpm");
    data->fond506 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/fond/fond506.xpm");
	data->fond506H = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/fond/fond506H.xpm");
	data->herbe1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe1.xpm");
	data->herbe2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe2.xpm");
	data->herbe3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe3.xpm");
	data->herbe4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbe4.xpm");
	data->herbeD = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbeD.xpm");
	data->herbeG = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/herbeG.xpm");
	data->terre1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre1.xpm");
	data->terre2 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre2.xpm");
	data->terre3 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre3.xpm");
	data->terre4 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terre4.xpm");
	data->terreD = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terreD.xpm");
	data->terreG = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/terreG.xpm");
	data->blockP1 = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockP1.xpm");
	data->blockB = ft_new_sprite(data,"sprite/Sheet-XPM-32PX-transparency/block/blockB.xpm");
}