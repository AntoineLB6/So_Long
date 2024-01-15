/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:22 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/10 14:21:48 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_assets
{
	void		*player;
	void		*wall;
	void		*floor;
	void		*cadavre;
	void		*exit;
	void		*ennemy;
	void		*player2;
	void		*player3;
}				t_assets;

typedef struct s_game
{
	int			xpos_p;
	int			ypos_p;
	int			coins_p;
	int			mv_count;
}				t_game;

typedef struct s_mapset
{
	int			x_size;
	int			y_size;
	char		**map;
	void		*mlx;
	void		*window;
}				t_mapset;

typedef struct s_vars
{
	t_assets	*assets;
	t_mapset	*mapset;
	t_game		*game_data;
	int			state;
}				t_vars;

void			get_assets(t_assets *assets, t_mapset *mapset, t_vars *vars);

int				exit_player(t_vars *vars, char c);
void			set_p_pos(t_vars *vars);
void			edit_compteur(t_vars *vars);

void			move_up(t_vars *vars);
void			move_down(t_vars *vars);
void			move_left(t_vars *vars);
void			move_right(t_vars *vars);

int				key_pressed(int key, t_vars *vars);
t_game			*create_p_pos(t_mapset *mapset, t_vars *vars);
void			init_vars(t_vars *vars, t_mapset *mapset);
int				anim(t_vars *vars);
void			play_game(t_mapset *mapset);

void			put_map_img(t_vars *vars, char c, int x, int y);
void			render_map(t_vars *vars);

int				map_ext(char *path);
int				file_size(char *argv);
char			*str_file(char *path);

int				rectangle_map(char **map);
int				elt_compteur(char **map, char e);
int				contour(char **map, t_mapset *mapset);
int				flood_fill_e(char **tmp, char sens, int x, int y);
int				flood_fill_p(char **tmp, char sens, int x, int y);

char			**map_copy(t_mapset *mapset, char **map);
int				interieur_e(char **map, t_mapset *mapset, char *map_str);
int				interieur_p(char **map, t_mapset *mapset, char *map_str);
char			**get_map_and_err(char *map_str, t_mapset *mapset);

void			free_solong(t_vars *vars, t_game *game_data, t_assets *assets,
					t_mapset *mapset);
void			ft_free_map(char **map);
void			ft_err(char *err);
void			ft_err_map(char *err, char **map, t_mapset *mapset,
					char *map_str);
void			ft_err_game(char *err, t_vars *vars);

void			free_assets(t_vars *vars, t_assets *assets);
void			free_mapset(t_mapset *mapset);
int				close_program(t_vars *vars);

#endif