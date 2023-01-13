/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:43 by merkol            #+#    #+#             */
/*   Updated: 2023/01/11 16:58:39 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	back_and_forward(t_game *g, int dir)
{
	int	x;
	int	y;

	x = (int)(g->ray.pos.x + g->ray.direction.x * g->rndr.move_speed);
	y = (int)(g->ray.pos.y + g->ray.direction.y * g->rndr.move_speed);
	if (dir == KEY_W)
	{
		if (g->ray.map[(int)g->ray.pos.y][x] == '0')
			g->ray.pos.x += g->ray.direction.x * g->rndr.move_speed;
		if (g->ray.map[y][(int)g->ray.pos.x] == '0')
			g->ray.pos.y += g->ray.direction.y * g->rndr.move_speed;
		return ;
	}
	x = (int)(g->ray.pos.x - g->ray.direction.x * g->rndr.move_speed);
	y = (int)(g->ray.pos.y - g->ray.direction.y * g->rndr.move_speed);
	if (g->ray.map[(int)g->ray.pos.y][x] == '0')
		g->ray.pos.x -= g->ray.direction.x * g->rndr.move_speed;
	if (g->ray.map[y][(int)g->ray.pos.x] == '0')
		g->ray.pos.y -= g->ray.direction.y * g->rndr.move_speed;
}

void	left_and_right(t_game *g, int dir)
{
	int	x;
	int	y;

	x = (int)(g->ray.pos.x + g->ray.direction.y * g->rndr.move_speed);
	y = (int)(g->ray.pos.y - g->ray.direction.x * g->rndr.move_speed);
	if (dir == KEY_A)
	{
		if (g->ray.map[(int)g->ray.pos.y][x] == '0')
			g->ray.pos.x += g->ray.direction.y * g->rndr.move_speed;
		if (g->ray.map[y][(int)g->ray.pos.x] == '0')
			g->ray.pos.y -= g->ray.direction.x * g->rndr.move_speed;
		return ;
	}
	x = (int)(g->ray.pos.x - g->ray.direction.y * g->rndr.move_speed);
	y = (int)(g->ray.pos.y + g->ray.direction.x * g->rndr.move_speed);
	if (g->ray.map[(int)g->ray.pos.y][x] == '0')
		g->ray.pos.x -= g->ray.direction.y * g->rndr.move_speed;
	if (g->ray.map[y][(int)g->ray.pos.x] == '0')
		g->ray.pos.y += g->ray.direction.x * g->rndr.move_speed;
}

void	move(t_game *g, int key)
{
	if (key == KEY_W || key == KEY_S)
		back_and_forward(g, key);
	else
		left_and_right(g, key);
}

int	key_hook(int key, t_game *g)
{
	if (key == KEY_RIGHT || key == KEY_LEFT)
		turn_angle(g, key);
	if (key == KEY_W || key == KEY_S)
		move(g, key);
	if (key == KEY_A || key == KEY_D)
		move(g, key);
	if (key == ESC)
		exit_game(g);
	return (key);
}
