#include "so_long.h"

int ft_verif_item(char **tab, t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y != map->size_y)
	{
		x = 0;
		while (x != map->size_x)
		{
			if(tab[y][x] == 'C')
				map->nbr_C++;
			if(tab[y][x] == 'E')
				map->nbr_E++;
			if(tab[y][x] == 'P')
				map->nbr_P++;
			x++;
		}
		y++;
	}
	if(map->nbr_C == 0 || map->nbr_E == 0 || map->nbr_P == 0 )
	{
		write(2, "Error\n", 7);
		write(2,"Nombre item non valide\n",24);
		return(0);
	}
	return (1);
}
