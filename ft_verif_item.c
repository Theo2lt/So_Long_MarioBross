#include "so_long.h"

int ft_verif_item(char **tab, t_map *data)
{
	int y;
	int x;

	y = 0;
	while (y != data->size_y)
	{
		x = 0;
		while (x != data->size_x)
		{
			if(tab[y][x] == 'C')
				data->nbr_C++;
			if(tab[y][x] == 'E')
				data->nbr_E++;
			if(tab[y][x] == 'P')
				data->nbr_P++;
			x++;
		}
		y++;
	}
	if(data->nbr_C == 0 || data->nbr_E == 0 || data->nbr_P == 0 )
	{
		write(2, "Error\n", 7);
		write(2,"Nombre item non valide\n",24);
		return(0);
	}
	return (1);
}
