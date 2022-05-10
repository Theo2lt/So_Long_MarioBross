#include "so_long.h"
#include "minilibx-linux/mlx.h"


int main(int argc, char **argv)
{
	char	**tab;
	t_map   *data;

	if(!ft_verif_arg(argc))
		return(0);
	tab = ft_create_tab(argv[1]);
	if(!tab)
		return (0);
	data = ft_lstnew_map(tab);
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

