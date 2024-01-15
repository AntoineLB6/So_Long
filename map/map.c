/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:16:31 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/10 14:22:01 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_copy(t_mapset *mapset, char **map)
{
	int		i;
	char	**new_copy;

	i = 0;
	new_copy = ft_calloc(mapset->y_size + 2, sizeof(char *));
	if (!new_copy)
		return (NULL);
	while (map[i])
	{
		new_copy[i] = ft_strdup(map[i]);
		i++;
	}
	new_copy[i] = NULL;
	return (new_copy);
}

int	interieur_e(char **map, t_mapset *mapset, char *map_str)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = map_copy(mapset, map);
	if (!tmp)
		ft_err_map("Malloc err", map, mapset, map_str);
	while (++y < mapset->y_size)
	{
		x = 0;
		while (++x < mapset->x_size - 1)
		{
			if (tmp[y][x] == 'P' && !flood_fill_e(tmp, '/', x, y))
			{
				ft_free_map(tmp);
				return (1);
			}
		}
	}
	ft_free_map(tmp);
	return (0);
}

int	interieur_p(char **map, t_mapset *mapset, char *map_str)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = map_copy(mapset, map);
	if (!tmp)
		ft_err_map("Malloc err", map, mapset, map_str);
	while (++y < mapset->y_size)
	{
		x = 0;
		while (++x < mapset->x_size - 1)
		{
			if (tmp[y][x] == 'C' && !flood_fill_p(tmp, '/', x, y))
			{
				ft_free_map(tmp);
				return (1);
			}
		}
	}
	ft_free_map(tmp);
	return (0);
}

char	**get_map_and_err(char *map_str, t_mapset *mapset)
{
	char	**map;
	int		i;

	i = -1;
	while (map_str[++i])
		if (!ft_strchr("01ECPD\n", map_str[i]))
			ft_err_map("Wrong char", NULL, mapset, map_str);
	map = ft_split(map_str, '\n');
	if (rectangle_map(map))
		ft_err_map("Rectangle map", map, mapset, map_str);
	if (elt_compteur(map, 'E') != 1 || elt_compteur(map, 'P') != 1
		|| elt_compteur(map, 'C') < 1)
		ft_err_map("Incorrect elements", map, mapset, map_str);
	if (contour(map, mapset))
		ft_err_map("Map not close", map, mapset, map_str);
	if (interieur_e(map, mapset, map_str))
		ft_err_map("Wrong way to E", map, mapset, map_str);
	if (interieur_p(map, mapset, map_str))
		ft_err_map("Wrong way to C", map, mapset, map_str);
	return (map);
}
