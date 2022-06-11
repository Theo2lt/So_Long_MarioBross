/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:15:59 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 13:20:57 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "/usr/include/X11/X.h"
# include "../minilibx-linux/mlx.h"

typedef struct t_map
{
	int	size_x;
	int	size_y;
	int	nbr_c;
	int	nbr_e;
	int	nbr_p;
}	t_map;

typedef struct t_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct t_perso
{
	int				position_y;
	int				position_x;
	int				direction;
	int				deplacement;
	int				vie;
	struct t_perso	*next;
}			t_perso;

typedef struct t_img
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
	struct t_win	*win;
	struct t_img	*rendu;
	struct t_img	*rendu_mur;
	struct t_perso	*perso;
	struct t_img	*piece1;
	struct t_img	*piece2;
	struct t_img	*piece3;
	struct t_img	*piece4;
	struct t_img	*piecetmp;
	struct t_img	*fond506;
	struct t_img	*fond506h;
	struct t_img	*herbe1;
	struct t_img	*herbe2;
	struct t_img	*herbe3;
	struct t_img	*herbe4;
	struct t_img	*herbed;
	struct t_img	*herbeg;
	struct t_img	*terre1;
	struct t_img	*terre2;
	struct t_img	*terre3;
	struct t_img	*terre4;
	struct t_img	*terred;
	struct t_img	*terreg;
	struct t_img	*blockp1;
	struct t_img	*blockp2;
	struct t_img	*blockp3;
	struct t_img	*blockp4;
	struct t_img	*blockptmp;
	struct t_img	*blockb;
	struct t_img	*svh;
	struct t_img	*srh;
	struct t_img	*piranhatmp;
	struct t_img	*piranha1;
	struct t_img	*piranha2;
	struct t_img	*piranha3;
	struct t_img	*piranha4;
	struct t_img	*piranha5;
	struct t_img	*piranha6;
	struct t_img	*mariotmp;
	struct t_img	*mario_hd1;
	struct t_img	*mario_hd2;
	struct t_img	*mario_hd3;
	struct t_img	*mario_hg1;
	struct t_img	*mario_hg2;
	struct t_img	*mario_hg3;
	struct t_img	*mario_init1;
	struct t_img	*mario_init2;
	struct t_img	*mario_sd1;
	struct t_img	*mario_sd2;
	struct t_img	*mario_sd3;
	struct t_img	*mario_sd4;
	struct t_img	*mario_sg1;
	struct t_img	*mario_sg2;
	struct t_img	*mario_sg3;
	struct t_img	*mario_sg4;

	struct t_perso	*troupe_piranha;

	struct t_map	*map;
	char			**tab;
}					t_data;

t_map			*ft_lstnew_map(char **tab);
int				ft_verif_map_mur_y(char **tab, t_map *data);
int				ft_verif_map_mur_x(char **tab, t_map *data);
int				ft_verif_map_forme(char **tab, t_map *data);
int				ft_verif_item(char **tab, t_map *map);
int				ft_tablen(char **tab);
char			*get_next_line(int fd);
int				ft_strlen(char *str);
char			*ft_initialise_element(char *str);
char			**ft_free(char **tab);
char			**ft_create_tab(char *name_map);
int				ft_verif_name_map(char *name);
int				ft_verif_arg(int argc);
int				ft_affichage(t_data *data);
void			ft_select_herbe(void	*mlx, void	*mlx_win, int x, int y);
void			ft_change_block(char **tab, t_map *data);
void			ft_put_background_img(t_map *map, t_data *data);
void			my_mlx_pixel_put(t_img *rendu, int y, int x, int color);
unsigned int	get_color_pixel(t_img *img, int y, int x);
void			ft_new_img_addr(t_data *data, char *path, t_img *img);
void			ft_init_all_sprite(t_data *data);
t_data			*ft_init_affichage(char **tab, t_map *map);
void			my_mlx_pixel_put(t_img *rendu, int y, int x, int color);
unsigned int	get_color_pixel(t_img *img, int y, int x);
void			my_put(t_img *rendu, t_img *img, int x, int y);
int				ft_init_perso_position(char **tab, t_data *data);
void			ft_reset_img(char **tab, t_map *map, t_data *data);
void			ft_mouve_perso_haut(int keycode, char **tab, t_map *map,
					t_data *data);
void			ft_mouve_perso_bas(int keycode, char **tab, t_map *map,
					t_data *data);
void			ft_mouve_perso_droite(int keycode, char **tab, t_map *map,
					t_data *data);
void			ft_mouve_perso_gauche(int keycode, char **tab, t_map *map,
					t_data *data);
void			ft_change_tap_block(char **tab, t_map *map, t_data *data);
void			ft_init_rendu_mur(char **tab, t_map *map, t_data *data);
void			ft_reset_rendu(char **tab, t_map *map, t_data *data);
char			*ft_itoa(int nb);
void			ft_my_mlx_string_put(t_data *data);
void			ft_exit(t_data *data);
void			ft_free_data(t_data *data);
void			ft_free_affichage(t_data *data);
void			ft_free_img(t_img *img, t_data *data);
void			ft_mario_img_sol(t_data *data, long int sleep);
void			ft_mario_img_haut(t_data *data, long int sleep);
void			ft_mario_img(t_data *data, long int sleep);
void			ft_piranha_img(t_data *data);
t_perso			*ft_lstnew(int position_y, int position_x);
t_perso			*ft_lstlast(t_perso *lst);
void			ft_lstadd_back(t_data *data, int position_y, int position_x);
int				ft_init_piranha_position(char **tab, t_data *data);
void			ft_lst_clean_piranaha(t_data *data);
t_data			*ft_init_all_rendu(t_data *data, t_map *map);
t_data			*ft_init_affichage(char **tab, t_map *map);
int				ft_init_perso_position(char **tab, t_data *data);
int				ft_init_piranha_position(char **tab, t_data *data);
void			ft_init_all_img_addr(t_data *data);
void			ft_init_all_sprite(t_data *data);
void			ft_new_img_addr(t_data *data, char *path, t_img *img);
t_img			*ft_new_sprite(void);
t_data			*ft_init_affichage(char **tab, t_map *map);
t_data			*ft_init_all_rendu(t_data *data, t_map *map);
t_data			*ft_init_data_mlx_win(t_data *data, t_map *map);
void			*ft_herbe_img(t_data *data, char **tab, int x, int y);
void			*ft_terre_img(t_data *data, char **tab, int x, int y);
int				ft_intput_game(int keycode, t_data *data);
void			ft_putstr(char *s);

#endif
