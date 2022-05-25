
#include "minilibx-linux/mlx.h"
#include "so_long.h"

// creer un nouveau node
t_map	*ft_lstnew_map(char **tab)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);

	new->size_x = ft_strlen(tab[0])-1;
	new->size_y = ft_tablen(tab);
	new->nbr_C  = 0;
	new->nbr_E  = 0;
	new->nbr_P  = 0;

	return (new);
}
/*
// creer un nouveau node
t_data	*ft_lstnew(void	*mlx ,char	*path)
{
	t_data	*new;
	int		img_width;
	int		img_height;
	
	//new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new = mlx_xpm_file_to_image(mlx,path, &img_width, &img_height);
	new->next = NULL;
	new->path = path;
	new->img_width = img_width;
	new->img_height = img_height;
	return (new);
}

// parcour la list jusqu'au dernier element
t_data	*ft_lstlast(t_data *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

// ajout la node au dernier element de la liste
void	ft_lstadd_back(t_data *alst, t_data *new)
{
	t_data	*tmp;
	if(!alst)
	{
		alst = new;
		return;
	}
	tmp = ft_lstlast(alst);
	tmp->next = new;
}

void	ft_lst_allfree(t_data *alst)
{
	t_data	*tmp;

	if (alst)
	{
		tmp = alst->next;
		free(alst);
		if (tmp)
			ft_lst_allfree(tmp);
	}
}

int	ft_lstsize(t_data *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_data	*ft_lst_cache_cache(t_data *lst, char *path)
{
	while (lst)
	{
		if(lst->path == path)
			return(lst);
		lst = lst->next;
	}
	return (NULL);
}
*/