/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:51:06 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/10 10:18:43 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_pressed(int key, t_vars *vars)
{
	if (key == XK_w)
		move_up(vars);
	else if (key == XK_s)
		move_down(vars);
	else if (key == XK_a)
		move_left(vars);
	else if (key == XK_d)
		move_right(vars);
	else if (key == XK_Escape)
		close_program(vars);
	return (0);
}

t_game	*create_p_pos(t_mapset *mapset, t_vars *vars)
{
	int		i;
	int		j;
	t_game	*game_data;

	i = 0;
	game_data = malloc(sizeof(t_game));
	if (!game_data)
		ft_err_game("Creating game data", vars);
	game_data->mv_count = -1;
	while (mapset->map[i])
	{
		j = 0;
		while (mapset->map[i][j])
		{
			if (mapset->map[i][j] == 'P')
			{
				game_data->xpos_p = j;
				game_data->ypos_p = i;
				return (game_data);
			}
			j++;
		}
		i++;
	}
	return (game_data);
}

void	init_vars(t_vars *vars, t_mapset *mapset)
{
	t_assets	*assets;
	t_game		*game_data;

	assets = malloc(sizeof(t_assets));
	get_assets(assets, mapset, vars);
	game_data = create_p_pos(mapset, vars);
	vars->assets = assets;
	vars->game_data = game_data;
	vars->mapset = mapset;
	render_map(vars);
}

int	anim(t_vars *vars)
{
	usleep(100000);
	if (vars->state == 1)
	{
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->player, vars->game_data->xpos_p * 48,
			vars->game_data->ypos_p * 48);
		vars->state = 2;
	}
	else if (vars->state == 2)
	{
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->player2, vars->game_data->xpos_p * 48,
			vars->game_data->ypos_p * 48);
		vars->state = 0;
	}
	else
	{
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->player3, vars->game_data->xpos_p * 48,
			vars->game_data->ypos_p * 48);
		vars->state = 1;
	}
	return (0);
}

void	play_game(t_mapset *mapset)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		ft_err_game("Alloc vars", vars);
	mapset->window = mlx_new_window(mapset->mlx, 48 * mapset->x_size, 48
			* (mapset->y_size + 1), "SO_LONG - ALEITE-B");
	init_vars(vars, mapset);
	edit_compteur(vars);
	vars->state = 0;
	mlx_key_hook(mapset->window, key_pressed, vars);
	mlx_hook(mapset->window, 17, 0, close_program, vars);
	mlx_loop_hook(mapset->mlx, anim, vars);
	mlx_loop(mapset->mlx);
}
