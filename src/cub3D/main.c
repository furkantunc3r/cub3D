/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:06:25 by merkol            #+#    #+#             */
/*   Updated: 2023/01/13 09:45:56 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	mouse_action(t_game *g)
{
	static int	temp_x;
	static int	x;
	static int	y;

	mlx_mouse_get_pos(g->rndr.win_ptr, &x, &y);
	if (x != temp_x)
	{
		if (x >= temp_x)
			turn_right(g);
		else
			turn_left(g);
		temp_x = x;
	}
	if (x >= WIN_WIDTH)
		mlx_mouse_move(g->rndr.win_ptr, 0, y);
	else if (x <= 0)
		mlx_mouse_move(g->rndr.win_ptr, WIN_WIDTH, y);
	else if (y >= WIN_HEIGHT)
		mlx_mouse_move(g->rndr.win_ptr, x, 0);
	else if (y <= 0)
		mlx_mouse_move(g->rndr.win_ptr, x, WIN_HEIGHT);
	mlx_mouse_hide();
}

int	loop(t_game *g)
{
	draw(g);
	mlx_put_image_to_window(g->rndr.mlx_ptr,
		g->rndr.win_ptr, g->rndr.img.img_ptr, 0, 0);
	mouse_action(g);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac < 2 || ac != 2)
		exit_error(NULL, "Too Few or Many Arguments!!\n");
	initialize(&g, *(++av));
	mlx_hook(g.rndr.win_ptr, 17, 0, exit_game, &g);
	mlx_hook(g.rndr.win_ptr, 2, 1, &key_hook, &g);
	mlx_loop_hook(g.rndr.mlx_ptr, loop, &g);
	mlx_loop(g.rndr.mlx_ptr);
	return (0);
}
