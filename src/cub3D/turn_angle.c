/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:58 by merkol            #+#    #+#             */
/*   Updated: 2023/01/10 10:49:00 by merkol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_right(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->ray.direction.x;
	old_plane_x = g->ray.plane.x;
	g->ray.direction.x = old_dir_x * cos(TURN_SPEED) - g->ray.direction.y
		* sin(TURN_SPEED);
	g->ray.direction.y = old_dir_x * sin(TURN_SPEED) + g->ray.direction.y
		* cos(TURN_SPEED);
	g->ray.plane.x = old_plane_x * cos(TURN_SPEED) - g->ray.plane.y
		* sin(TURN_SPEED);
	g->ray.plane.y = old_plane_x * sin(TURN_SPEED) + g->ray.plane.y
		* cos(TURN_SPEED);
}

void	turn_left(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->ray.direction.x;
	old_plane_x = g->ray.plane.x;
	g->ray.direction.x = old_dir_x * cos(-TURN_SPEED) - g->ray.direction.y
		* sin(-TURN_SPEED);
	g->ray.direction.y = old_dir_x * sin(-TURN_SPEED) + g->ray.direction.y
		* cos(-TURN_SPEED);
	g->ray.plane.x = old_plane_x * cos(-TURN_SPEED) - g->ray.plane.y
		* sin(-TURN_SPEED);
	g->ray.plane.y = old_plane_x * sin(-TURN_SPEED) + g->ray.plane.y
		* cos(-TURN_SPEED);
}

void	turn_angle(t_game *g, int dir)
{
	if (dir == KEY_RIGHT)
		turn_right(g);
	if (dir == KEY_LEFT)
		turn_left(g);
}
