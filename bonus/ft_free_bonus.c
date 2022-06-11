/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:51 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:41:29 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	ft_free_data(t_data *data)
{
	if (data->win->mlx)
		free(data->win->mlx);
	if (data->perso)
		free(data->perso);
	if (data->rendu_mur)
		free(data->rendu_mur);
	if (data->rendu)
		free(data->rendu);
	if (data->win)
		free(data->win);
	if (data->tab)
		ft_free(data->tab);
	if (data->map)
		free(data->map);
	if (data->troupe_piranha)
		ft_lst_clean_piranaha(data);
	if (data)
		free(data);
}
