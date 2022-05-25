#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "/usr/include/X11/X.h"
#include "minilibx-linux/mlx.h"

struct t_data;

typedef struct t_map
{
	int	size_x;
	int	size_y;
	int	nbr_C;
	int nbr_E;
	int	nbr_P;
}	t_map;

typedef struct	t_rendu {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_rendu;

typedef struct t_win
{
	void *mlx;
	void *mlx_win;
} 				t_win;

typedef	struct t_sprite
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_sprite;


typedef struct t_data
{
	struct	t_win 		*win;
	struct	t_rendu 	*rendu;
	struct	t_sprite	*piece1;
	struct	t_sprite	*piece2;
	struct	t_sprite	*piece3;
	struct	t_sprite	*piece4;
	struct	t_sprite	*fond506;
	struct	t_sprite	*fond506H;
	struct  t_sprite    *herbe1;
	struct  t_sprite    *herbe2;
	struct  t_sprite    *herbe3;
	struct  t_sprite    *herbe4;
	struct  t_sprite    *herbeD;
	struct  t_sprite    *herbeG;
	struct  t_sprite    *terre1;
	struct  t_sprite    *terre2;
	struct  t_sprite    *terre3;
	struct  t_sprite    *terre4;
	struct  t_sprite    *terreD;
	struct  t_sprite    *terreG;
	struct  t_sprite    *blockP1;
	struct  t_sprite    *blockB;
}				t_data;



t_map	*ft_lstnew_map(char **tab);
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
int 	ft_affichage(char **tab, t_map *data);
char    *ft_strdup(char *s1);
void 	ft_select_herbe(void	*mlx, void	*mlx_win ,int x, int y);
void 	ft_change_block(char **tab, t_map *data);
void 	ft_put_background_img(t_map *map, t_data *data);
void	my_mlx_pixel_put(t_rendu *rendu, int y, int x, int color);
unsigned int   	 get_color_pixel(t_sprite *img, int y, int x);
void	my_put(t_data *data,t_sprite *img,int x,int y);
t_sprite *ft_new_sprite(t_data *data, char *path);
void ft_init_all_sprite(t_data *data);

#define PRINTS(x) printf("%s\n", x);
#define PRINTP(x) printf("%p\n", x);

#endif
