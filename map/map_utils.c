/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:34:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:00:44 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[j])
		{
			if (ft_strlen(map[i]) != ft_strlen(map[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	elt_compteur(char **map, char e)
{
	int		i;
	int		j;
	int		compteur;

	i = 0;
	compteur = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == e)
				compteur++;
			j++;
		}
		i++;
	}
	return (compteur);
}

int	contour(char **map, t_mapset *mapset)
{
	int		i;

	i = 0;
	while (map[0][i++])
		if (map[0][i] != '1' && map[0][i] != '\0')
			return (1);
	i = 0;
	while (map[mapset->y_size][i++])
		if (map[mapset->y_size][i] != '1' && map[mapset->y_size][i] != '\0')
			return (1);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][0] != '1')
			return (1);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][mapset->x_size - 1] != '1')
			return (1);
	return (0);
}

int	flood_fill_e(char **tmp, char sens, int x, int y)
{
	int	res;

	res = 0;
	if (tmp[y][x] == 'E')
		return (1);
	tmp[y][x] = '*';
	if (ft_strchr("0CPE", tmp[y - 1][x]) && sens != 'U')
		res += flood_fill_e(tmp, 'D', x, y - 1);
	if (ft_strchr("0CPE", tmp[y + 1][x]) && sens != 'D')
		res += flood_fill_e(tmp, 'U', x, y + 1);
	if (ft_strchr("0CPE", tmp[y][x - 1]) && sens != 'L')
		res += flood_fill_e(tmp, 'R', x - 1, y);
	if (ft_strchr("0CPE", tmp[y][x + 1]) && sens != 'R')
		res += flood_fill_e(tmp, 'L', x + 1, y);
	return (res);
}

int	flood_fill_p(char **tmp, char sens, int x, int y)
{
	int	res;

	res = 0;
	if (tmp[y][x] == 'P')
		return (1);
	tmp[y][x] = '*';
	if (ft_strchr("0CP", tmp[y - 1][x]) && sens != 'U')
		res += flood_fill_p(tmp, 'D', x, y - 1);
	if (ft_strchr("0CP", tmp[y + 1][x]) && sens != 'D')
		res += flood_fill_p(tmp, 'U', x, y + 1);
	if (ft_strchr("0CP", tmp[y][x - 1]) && sens != 'L')
		res += flood_fill_p(tmp, 'R', x - 1, y);
	if (ft_strchr("0CP", tmp[y][x + 1]) && sens != 'R')
		res += flood_fill_p(tmp, 'L', x + 1, y);
	return (res);
}
