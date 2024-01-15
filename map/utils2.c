/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:11:58 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:26:22 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_assets(t_vars *vars, t_assets *assets)
{
	if (assets->player)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->player);
	if (assets->wall)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->wall);
	if (assets->floor)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->floor);
	if (assets->cadavre)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->cadavre);
	if (assets->exit)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->exit);
	if (assets->ennemy)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->ennemy);
	if (assets->player2)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->player2);
	if (assets->player3)
		mlx_destroy_image(vars->mapset->mlx, vars->assets->player3);
	free(assets);
}

void	free_mapset(t_mapset *mapset)
{
	int	i;

	i = 0;
	if (mapset->window)
		mlx_destroy_window(mapset->mlx, mapset->window);
	if (mapset->mlx)
	{
		mlx_destroy_display(mapset->mlx);
		free(mapset->mlx);
	}
	if (mapset->map || (*mapset->map))
	{
		while (mapset->map[i])
			free(mapset->map[i++]);
		free(mapset->map);
	}
	free(mapset);
}

int	close_program(t_vars *vars)
{
	free_solong(vars, vars->game_data, vars->assets, vars->mapset);
	exit(0);
}
