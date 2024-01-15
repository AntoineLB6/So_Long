/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:25:57 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 14:55:06 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_map_img(t_vars *vars, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->player, x * 48, y * 48);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->exit, x * 48, y * 48);
	else if (c == 'C')
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->cadavre, x * 48, y * 48);
	else if (c == '1')
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->wall, x * 48, y * 48);
	else if (c == 'D')
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->ennemy, x * 48, y * 48);
	else
		mlx_put_image_to_window(vars->mapset->mlx, vars->mapset->window,
			vars->assets->floor, x * 48, y * 48);
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->mapset->map[i])
	{
		j = 0;
		while (vars->mapset->map[i][j])
		{
			put_map_img(vars, vars->mapset->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
