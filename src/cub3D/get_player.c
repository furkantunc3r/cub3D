/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:32 by merkol            #+#    #+#             */
/*   Updated: 2023/01/09 16:07:32 by merkol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->rndr.map.map[++i])
	{
		j = -1;
		while (g->rndr.map.map[i][++j])
		{
			if (g->rndr.map.map[i][j] == 'N' || g->rndr.map.map[i][j] == 'S' \
				|| g->rndr.map.map[i][j] == 'E' || g->rndr.map.map[i][j] == 'W')
			{
				g->rndr.map.player_x = j;
				g->rndr.map.player_y = i;
				g->rndr.map.pov_char = g->rndr.map.map[i][j];
				init_direction(g, g->rndr.map.map[i][j]);
				g->rndr.map.map[i][j] = '0';
				return ;
			}
		}
	}
	exit_error(g, "Missing Character!\n");
}
