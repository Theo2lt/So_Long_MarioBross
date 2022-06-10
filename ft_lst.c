/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:13:32 by tliot             #+#    #+#             */
/*   Updated: 2022/06/10 18:20:04 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

// creer un nouveau node
t_map	*ft_lstnew_map(char **tab)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->size_x = ft_strlen(tab[0]) - 1;
	new->size_y = ft_tablen(tab);
	new->nbr_c = 0;
	new->nbr_e = 0;
	new->nbr_p = 0;
	return (new);
}

t_perso	*ft_lstnew(int position_y, int position_x)
{
	t_perso	*new_elem;

	new_elem = malloc(sizeof(t_perso));
	if (!new_elem)
		return (NULL);
	new_elem->position_y = position_y;
	new_elem->position_x = position_x;
	new_elem->direction = 1;
	new_elem->next = NULL;
	return (new_elem);
}

t_perso	*ft_lstlast(t_perso *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_data *data, int position_y, int position_x)
{
	t_perso	*last_elem;

	if (!data->troupe_piranha)
		data->troupe_piranha = ft_lstnew(position_y, position_x);
	else
	{
		last_elem = ft_lstlast(data->troupe_piranha);
		last_elem->next = ft_lstnew(position_y, position_x);
	}
}

void	ft_lst_clean_piranaha(t_data *data)
{
	t_perso	*save_elem;

	while (data->troupe_piranha)
	{
		save_elem = data->troupe_piranha;
		data->troupe_piranha = data->troupe_piranha->next;
		free(save_elem);
	}
}
