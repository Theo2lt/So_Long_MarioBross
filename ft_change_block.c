#include "so_long.h"

void ft_change_block(char **tab, t_map *data)    
{
    int y;
    int x;
    int block;

    x = 0;
    while(x < data->size_x)
    {
        block = 1;
        y = data->size_y-1;
        while(0 < y)
        {
            if(tab[y][x] == '1' && block == 0)
               {
                    tab[y][x] = '2';
                    if(tab[y-1][x] != '1')
                        tab[y][x] = '3';
               }
            else if(tab[y][x] != '1' )
                block = 0;
            y--;
        }

        x++;
    }
}