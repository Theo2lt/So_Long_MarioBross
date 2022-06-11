/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:59:19 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:42:33 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}

void	main2(char	**tab, t_map	*map, t_data	*data)
{
	data = ft_init_affichage(tab, map);
	if (data == NULL)
		ft_exit(data);
	else
	{
		ft_init_perso_position(tab, data);
		ft_affichage(data);
	}
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_map	*map;
	t_data	*data;

	if (!ft_verif_arg(argc))
		return (0);
	tab = ft_create_tab(argv[1]);
	if (!tab)
		return (0);
	map = ft_lstnew_map(tab);
	if (!ft_verif_map_forme(tab, map) || !ft_verif_map_mur_y(tab, map)
		|| !ft_verif_map_mur_x(tab, map) || !ft_verif_item(tab, map))
	{
		tab = ft_free(tab);
		free(map);
		return (0);
	}
	ft_change_block(tab, map);
	data = NULL;
	main2(tab, map, data);
}
