/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:27:12 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:19:39 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->mapset->map[vars->game_data->ypos_p
			- 1][vars->game_data->xpos_p] == '1')
		return ;
	if (vars->mapset->map[vars->game_data->ypos_p
			- 1][vars->game_data->xpos_p] == 'E'
		|| vars->mapset->map[vars->game_data->ypos_p
		- 1][vars->game_data->xpos_p] == 'D')
		if (!exit_player(vars, vars->mapset->map[vars->game_data->ypos_p
					- 1][vars->game_data->xpos_p]))
			return ;
	if (vars->mapset->map[vars->game_data->ypos_p
			- 1][vars->game_data->xpos_p] == 'C')
		vars->game_data->coins_p++;
	vars->mapset->map[vars->game_data->ypos_p
		- 1][vars->game_data->xpos_p] = 'P';
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p] = '0';
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->floor, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	set_p_pos(vars);
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->player, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	edit_compteur(vars);
}

void	move_down(t_vars *vars)
{
	if (vars->mapset->map[vars->game_data->ypos_p
			+ 1][vars->game_data->xpos_p] == '1')
		return ;
	if (vars->mapset->map[vars->game_data->ypos_p
			+ 1][vars->game_data->xpos_p] == 'E'
		|| vars->mapset->map[vars->game_data->ypos_p
		+ 1][vars->game_data->xpos_p] == 'D')
		if (!exit_player(vars, vars->mapset->map[vars->game_data->ypos_p
					+ 1][vars->game_data->xpos_p]))
			return ;
	if (vars->mapset->map[vars->game_data->ypos_p
			+ 1][vars->game_data->xpos_p] == 'C')
		vars->game_data->coins_p++;
	vars->mapset->map[vars->game_data->ypos_p
		+ 1][vars->game_data->xpos_p] = 'P';
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p] = '0';
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->floor, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	set_p_pos(vars);
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->player, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	edit_compteur(vars);
}

void	move_left(t_vars *vars)
{
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		- 1] == '1')
		return ;
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		- 1] == 'E'
		|| vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		- 1] == 'D')
		if (!exit_player(vars,
				vars->mapset->map[vars->game_data
					->ypos_p][vars->game_data->xpos_p - 1]))
			return ;
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		- 1] == 'C')
		vars->game_data->coins_p++;
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		- 1] = 'P';
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p] = '0';
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->floor, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	set_p_pos(vars);
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->player, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	edit_compteur(vars);
}

void	move_right(t_vars *vars)
{
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		+ 1] == '1')
		return ;
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		+ 1] == 'E'
		|| vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		+ 1] == 'D')
		if (!exit_player(vars,
				vars->mapset->map[vars->game_data
					->ypos_p][vars->game_data->xpos_p + 1]))
			return ;
	if (vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		+ 1] == 'C')
		vars->game_data->coins_p++;
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p
		+ 1] = 'P';
	vars->mapset->map[vars->game_data->ypos_p][vars->game_data->xpos_p] = '0';
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->floor, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	set_p_pos(vars);
	mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
		vars->assets->player, vars->game_data->xpos_p * 48,
		vars->game_data->ypos_p * 48);
	edit_compteur(vars);
}
