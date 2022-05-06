#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>


typedef struct t_map
{
	int	size_x;
	int	size_y;
	int	nbr_C;
	int nbr_E;
	int	nbr_P;
}	t_map;

t_map	*ft_lstnew(char **tab);
int     ft_verif_map_mur_y(char **tab,t_map *data);
int     ft_verif_map_mur_x(char **tab,t_map *data);
int     ft_verif_map_forme(char **tab,t_map *data);
int     ft_verif_item(char **tab,t_map   *data);
int     ft_tablen(char **tab);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_initialise_element(char *str);
char	**ft_free(char **tab);
char	**ft_create_tab(char *name_map);
int		ft_verif_name_map(char *name);
int		ft_verif_arg(int argc);

#endif
