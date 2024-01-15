/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:17:40 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_assets(t_assets *assets, t_mapset *mapset, t_vars *vars)
{
	int			width;
	int			height;

	assets->player = mlx_xpm_file_to_image(mapset->mlx, "assets/player.xpm",
			&width, &height);
	assets->wall = mlx_xpm_file_to_image(mapset->mlx, "assets/wall.xpm", &width,
			&height);
	assets->floor = mlx_xpm_file_to_image(mapset->mlx, "assets/floor.xpm",
			&width, &height);
	assets->cadavre = mlx_xpm_file_to_image(mapset->mlx, "assets/cadavre.xpm",
			&width, &height);
	assets->exit = mlx_xpm_file_to_image(mapset->mlx, "assets/exit.xpm", &width,
			&height);
	assets->player2 = mlx_xpm_file_to_image(mapset->mlx,
			"assets/player_walk1.xpm", &width, &height);
	assets->player3 = mlx_xpm_file_to_image(mapset->mlx,
			"assets/player_walk2.xpm", &width, &height);
	assets->ennemy = mlx_xpm_file_to_image(mapset->mlx, "assets/ennemy.xpm",
			&width, &height);
	if (!assets->player || !assets->wall || !assets->floor || !assets->cadavre
		|| !assets->exit || !assets->ennemy || !assets->player2
		|| !assets->player3)
		ft_err_game("Create images", vars);
}
