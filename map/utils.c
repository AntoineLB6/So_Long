/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:11:58 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/10 14:20:26 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_solong(t_vars *vars, t_game *game_data, t_assets *assets,
		t_mapset *mapset)
{
	if (assets)
		free_assets(vars, assets);
	if (game_data)
		free(game_data);
	if (mapset)
		free_mapset(mapset);
	if (vars)
		free(vars);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !(*map))
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_err(char *err)
{
	write(2, "Error\n", 6);
	perror(err);
	exit(EXIT_FAILURE);
}

void	ft_err_map(char *err, char **map, t_mapset *mapset, char *map_str)
{
	ft_free_map(map);
	free(mapset);
	free(map_str);
	write(2, "Error\n", 6);
	perror(err);
	exit(EXIT_FAILURE);
}

void	ft_err_game(char *err, t_vars *vars)
{
	free_solong(vars, vars->game_data, vars->assets, vars->mapset);
	write(2, "Error\n", 6);
	perror(err);
	exit(EXIT_FAILURE);
}
