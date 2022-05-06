

#include "so_long.h"

// creer un nouveau node
t_map	*ft_lstnew(char **tab)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);

	new->size_x = ft_strlen(tab[0]);
	new->size_y = ft_tablen(tab);
	new->nbr_C  = 0;
	new->nbr_E  = 0;
	new->nbr_P  = 0;

	return (new);
}
