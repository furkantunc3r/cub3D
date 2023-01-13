/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:40 by merkol            #+#    #+#             */
/*   Updated: 2023/01/11 09:43:55 by merkol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_null(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		g->rndr.tex.imgs[i].path = NULL;
		g->rndr.tex.imgs[i].img_ptr = NULL;
	}
	g->rndr.mlx_ptr = NULL;
	g->rndr.win_ptr = NULL;
	g->rndr.map.map = NULL;
	g->rndr.map.gnl_buffer = NULL;
	g->rndr.map.elem_count = 0;
	g->rndr.map.fd_cub = -1;
	g->rndr.map.tile_size = 64;
	g->rndr.res_width = WIN_WIDTH;
	g->rndr.res_height = WIN_HEIGHT;
	g->rndr.move_speed = 0.1;
}

void	check_imgptr(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!g->rndr.tex.imgs[i].img_ptr)
			exit_error(g, "File doesn't exist\n");
}

void	init_assets(t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < 4)
		g->rndr.tex.imgs[i].img_ptr = mlx_xpm_file_to_image(g->rndr.mlx_ptr,
				g->rndr.tex.imgs[i].path, &x, &y);
	check_imgptr(g);
	i = -1;
	while (++i < 4)
		g->rndr.tex.imgs[i].addr = \
			mlx_get_data_addr(g->rndr.tex.imgs[i].img_ptr,
				&g->rndr.tex.imgs[i].bpp, &g->rndr.tex.imgs[i].line_len,
				&g->rndr.tex.imgs[i].endian);
}

void	init_mlx(t_game *g)
{
	g->rndr.mlx_ptr = mlx_init();
	g->rndr.win_ptr = mlx_new_window(g->rndr.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	g->rndr.img.img_ptr = mlx_new_image(g->rndr.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	g->rndr.img.addr = mlx_get_data_addr(g->rndr.img.img_ptr,
			&g->rndr.img.bpp, &g->rndr.img.line_len, &g->rndr.img.endian);
}

int	initialize(t_game *g, char *cub)
{
	init_null(g);
	file_parse(g, cub);
	init_mlx(g);
	init_assets(g);
	init_ray(g);
	return (0);
}
