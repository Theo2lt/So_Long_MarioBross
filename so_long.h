#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "/usr/include/X11/X.h"
#include "minilibx-linux/mlx.h"


typedef struct t_map
{
	int	size_x;
	int	size_y;
	int	nbr_C;
	int nbr_E;
	int	nbr_P;
}	t_map;

typedef struct t_win
{
	void *mlx;
	void *mlx_win;
} 				t_win;

typedef struct t_perso
{
	int position_y;
	int position_x;
	int deplacement;
	int vie;
}			t_perso;

typedef	struct t_img
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


typedef struct t_data
{
	struct	t_win 		*win;
	struct	t_img 	*rendu;
	struct  t_img		*rendu_mur;
	struct  t_perso		*perso;
	struct	t_img	*piece1;
	struct	t_img	*piece2;
	struct	t_img	*piece3;
	struct	t_img	*piece4;
	struct	t_img	*piecetmp;
	struct	t_img	*fond506;
	struct	t_img	*fond506H;
	struct  t_img   *herbe1;
	struct  t_img   *herbe2;
	struct  t_img   *herbe3;
	struct  t_img   *herbe4;
	struct  t_img   *herbeD;
	struct  t_img   *herbeG;
	struct  t_img   *terre1;
	struct  t_img   *terre2;
	struct  t_img   *terre3;
	struct  t_img   *terre4;
	struct  t_img   *terreD;
	struct  t_img   *terreG;
	struct  t_img   *blockP1;
	struct  t_img   *blockP2;
	struct  t_img   *blockP3;
	struct  t_img   *blockP4;
	struct  t_img   *blockPtmp;
	struct  t_img   *blockB;
	struct  t_img   *mario;
	struct  t_img   *SVH;
	struct  t_img   *SRH;
	struct	t_map		*map;
	char		**tab;
}				t_data;



t_map	*ft_lstnew_map(char **tab);
int     ft_verif_map_mur_y(char **tab,t_map *data);
int     ft_verif_map_mur_x(char **tab,t_map *data);
int     ft_verif_map_forme(char **tab,t_map *data);
int     ft_verif_item(char **tab,t_map *map);
int     ft_tablen(char **tab);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_initialise_element(char *str);
char	**ft_free(char **tab);
char	**ft_create_tab(char *name_map);
int		ft_verif_name_map(char *name);
int		ft_verif_arg(int argc);
int 	ft_affichage(t_data *data);
void 	ft_select_herbe(void	*mlx, void	*mlx_win ,int x, int y);
void 	ft_change_block(char **tab, t_map *data);
void 	ft_put_background_img(t_map *map, t_data *data);
void	my_mlx_pixel_put(t_img *rendu, int y, int x, int color);
unsigned int   	 get_color_pixel(t_img *img, int y, int x);
t_img 			*ft_new_sprite(t_data *data, char *path);
void ft_init_all_sprite(t_data *data);
t_data *ft_init_affichage(char **tab, t_map *map);
void	my_mlx_pixel_put(t_img *rendu, int y, int x, int color);
unsigned int    get_color_pixel(t_img *img, int y, int x);
void	my_put(t_img *rendu,t_img *img,int x,int y);
int ft_init_perso_position(char **tab, t_data *data);
void ft_reset_img(char **tab, t_map *map, t_data *data);
void ft_mouve_perso_haut(int keycode ,char **tab, t_map *map, t_data *data);
void ft_mouve_perso_bas(int keycode ,char **tab, t_map *map, t_data *data);
void ft_mouve_perso_droite(int keycode ,char **tab, t_map *map, t_data *data);
void ft_mouve_perso_gauche(int keycode ,char **tab, t_map *map, t_data *data);
void ft_change_tap_block(char **tab, t_map *map, t_data *data);
void ft_init_rendu_mur(char **tab, t_map *map, t_data *data);
void ft_reset_rendu(char **tab, t_map *map, t_data *data);
char	*ft_itoa(int nb);
void 	ft_my_mlx_string_put(t_data *data);
void ft_exit(t_data *data);

#endif
