/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:03 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 12:41:55 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_xy_size(char *str, t_mapset *mapset)
{
	int			countx;
	int			i;
	int			county;

	countx = 0;
	i = 0;
	county = 0;
	while (ft_strchr("01ECPD", str[countx]))
		countx++;
	mapset->x_size = countx;
	while (str[i])
	{
		if (str[i] == '\n')
			county++;
		i++;
	}
	mapset->y_size = county;
	mapset->map = NULL;
}

void	launch(char *map_str)
{
	t_mapset	*mapset;

	mapset = malloc(sizeof(t_mapset));
	if (!mapset)
		return ;
	get_xy_size(map_str, mapset);
	mapset->map = get_map_and_err(map_str, mapset);
	free(map_str);
	mapset->mlx = mlx_init();
	mapset->window = NULL;
	if (!mapset->mlx)
	{
		free_mapset(mapset);
		ft_err("No env var");
	}
	play_game(mapset);
}

int	main(int argc, char **argv)
{
	char	*map_str;

	if (argc < 2)
		ft_err("No map send");
	map_str = str_file(argv[1]);
	if (!map_str)
		return (1);
	launch(map_str);
}
