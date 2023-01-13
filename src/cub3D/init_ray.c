/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:37 by merkol            #+#    #+#             */
/*   Updated: 2023/01/12 12:38:15 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_ray_number(t_game *g)
{
	g->ray.map = g->rndr.map.map;
	g->ray.map_height = dbl_array_size(g->ray.map);
	g->ray.map_width = get_longest_row(g->ray.map);
	g->ray.fov = M_PI / 4;
	g->ray.tile_size = 64;
	g->ray.hit = 0;
	g->ray.side = 0;
	g->ray.perp_wall_dist = 0;
	g->ray.wall_x = 0;
	g->ray.tex_x = 0;
	g->ray.tex_y = 0;
	g->ray.tex_pos = 0;
	g->ray.camera_x = 0;
	g->ray.row_distance = 0;
}

void	init_ray_struct(t_game *g)
{
	g->ray.res = assign_point(WIN_WIDTH, WIN_HEIGHT);
	g->ray.pos = assign_point(g->rndr.map.player_x + 0.5,
			g->rndr.map.player_y + 0.5);
	g->ray.in_map = assign_point(0, 0);
	g->ray.delta_dist = assign_point(0, 0);
	g->ray.side_dist = assign_point(0, 0);
	g->ray.step = assign_point(0, 0);
	g->ray.line = init_line(0, 0, 0, 0);
	g->ray.ray_dir = assign_point(0, 0);
	g->ray.tex = assign_point(0, 0);
}

void	init_ray(t_game *g)
{
	init_ray_number(g);
	get_player_pos(g);
	init_ray_struct(g);
	g->ray.render = g->rndr;
}
