#include "so_long.h"

void ft_mouve_perso_haut(int keycode ,char **tab, t_map *map, t_data *data)
{

	if(keycode == 119)
	{
		if((tab[data->perso->position_y-1][data->perso->position_x] != '1' && tab[data->perso->position_y-1][data->perso->position_x] != '3'))
		{
            if(tab[data->perso->position_y-1][data->perso->position_x] == '2')
            {   
                ft_change_tap_block(tab, map, data);
            }    
            else
            {
			    if(tab[data->perso->position_y-1][data->perso->position_x] == 'C')
			    	map->nbr_C--;
			    tab[data->perso->position_y-1][data->perso->position_x] = 'P';
			    tab[data->perso->position_y][data->perso->position_x] = '0';
			    data->perso->position_y -= 1;
            }
		}
	}
	
}


void ft_mouve_perso_bas(int keycode ,char **tab, t_map *map, t_data *data)
{

	if(keycode == 115)
	{
		if(tab[data->perso->position_y+1][data->perso->position_x] != '1' && tab[data->perso->position_y+1][data->perso->position_x] != '3' && tab[data->perso->position_y+1][data->perso->position_x] != '2')
		{
			if(tab[data->perso->position_y+1][data->perso->position_x] == 'C')
				map->nbr_C--;
			tab[data->perso->position_y+1][data->perso->position_x] = 'P';
			tab[data->perso->position_y][data->perso->position_x] = '0';
			data->perso->position_y += 1;
		}
	}
	
}

void ft_mouve_perso_droite(int keycode ,char **tab, t_map *map, t_data *data)
{

	if(keycode == 100)
	{
		if(tab[data->perso->position_y][data->perso->position_x+1] != '1' && tab[data->perso->position_y][data->perso->position_x+1] != '3' && tab[data->perso->position_y][data->perso->position_x+1] != '2')
		{
			if(tab[data->perso->position_y][data->perso->position_x+1] == 'C')
				map->nbr_C--;
			tab[data->perso->position_y][data->perso->position_x+1] = 'P';
			tab[data->perso->position_y][data->perso->position_x] = '0';
			data->perso->position_x += 1;
		}
	}
	
}

void ft_mouve_perso_gauche(int keycode ,char **tab, t_map *map, t_data *data)
{

	if(keycode == 97)
	{
		if(tab[data->perso->position_y][data->perso->position_x-1] != '1' && tab[data->perso->position_y][data->perso->position_x-1] != '3' && tab[data->perso->position_y][data->perso->position_x-1] != '2')
		{
			if(tab[data->perso->position_y][data->perso->position_x-1] == 'C')
				map->nbr_C--;
			tab[data->perso->position_y][data->perso->position_x-1] = 'P';
			tab[data->perso->position_y][data->perso->position_x] = '0';
			data->perso->position_x -= 1;
		}
	}
	
}