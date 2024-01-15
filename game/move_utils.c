/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:27:12 by aleite-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:19:30 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_player(t_vars *vars, char c)
{
	if (c == 'E' && elt_compteur(vars->mapset->map, 'C') == 0)
	{
		ft_putendl_fd("Tu as gagné.", 1);
		close_program(vars);
	}
	else if (c == 'D')
	{
		ft_putendl_fd("Tu as perdu.", 1);
		close_program(vars);
	}
	else
	{
		ft_putendl_fd("Tu n'as pas encore collecté tous les cadavres.", 1);
		return (0);
	}
	return (1);
}

void	set_p_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->mapset->map[i])
	{
		j = 0;
		while (vars->mapset->map[i][j])
		{
			if (vars->mapset->map[i][j] == 'P')
			{
				vars->game_data->xpos_p = j;
				vars->game_data->ypos_p = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	edit_compteur(t_vars *vars)
{
	int		i;
	char	*nb;

	i = 0;
	vars->game_data->mv_count++;
	ft_putnbr_fd(vars->game_data->mv_count, 1);
	write(1, "\n", 1);
	nb = ft_itoa(vars->game_data->mv_count);
	while (vars->mapset->map[0][i])
	{
		put_map_img(vars, vars->mapset->map[0][i], 0, i);
		i++;
	}
	mlx_string_put(vars->mapset->mlx, vars->mapset->window, 24, 24, 0xffffff,
		nb);
	free(nb);
}
