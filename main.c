#include "so_long.h"
#include "minilibx-linux/mlx.h"


int main(int argc, char **argv)
{
	char	**tab;
	t_map   *map;
	t_data	*data;

	if(!ft_verif_arg(argc))
		return(0);
	tab = ft_create_tab(argv[1]);
	if(!tab)
		return (0);
	map = ft_lstnew_map(tab);
	
	if(!ft_verif_map_forme(tab, map) || !ft_verif_map_mur_y(tab, map) || !ft_verif_map_mur_x(tab, map) || !ft_verif_item(tab,map))
	{
		tab = ft_free(tab);
		free(map);
		return (0);
	}
	ft_change_block(tab, map);
	data = ft_init_affichage(tab,map);
	if(data == 0)
		ft_exit(data);
	else
	{
		data->tab = tab;
		data->map = map;
		ft_init_perso_position(tab,data);
		ft_affichage(data);
	}
}