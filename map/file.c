/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:07:25 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 11:01:35 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_ext(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 4)
		return (1);
	i -= 4;
	if (ft_strncmp(path + i, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	file_size(char *argv)
{
	int		file;
	int		size;
	char	c;

	size = 0;
	file = open(argv, O_RDONLY);
	if (file < 0)
		ft_err("File open");
	while (read(file, &c, 1) > 0)
		size++;
	if (read(file, &c, 1) < 0)
		ft_err("Unreadable");
	close(file);
	return (size);
}

char	*str_file(char *path)
{
	int		size_of_file;
	int		file;
	char	*buff;
	int		i;

	i = 0;
	if (map_ext(path))
		ft_err("Incorrect map link");
	size_of_file = file_size(path);
	if (size_of_file == -1)
		ft_err("Map size");
	buff = malloc(sizeof(char) * (size_of_file + 1));
	if (!buff)
		return (NULL);
	file = open(path, O_RDONLY);
	if (read(file, buff, size_of_file) > 0)
	{
		buff[size_of_file] = '\0';
		return (buff);
	}
	else
		ft_err("Unreadable");
	return (NULL);
}
