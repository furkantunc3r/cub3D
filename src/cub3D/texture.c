/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:06:40 by merkol            #+#    #+#             */
/*   Updated: 2023/01/10 15:27:03 by merkol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	tex_setup(t_ray *r)
{
	if (r->side == 0)
		r->wall_x = r->pos.y + r->perp_wall_dist * r->ray_dir.y;
	else
		r->wall_x = r->pos.x + r->perp_wall_dist * r->ray_dir.x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)(r->tile_size));
	if ((r->side == 0 && r->ray_dir.x > 0) \
			|| (r->side == 1 && r->ray_dir.y < 0))
		r->tex_x = r->tile_size - r->tex_x - 1;
	r->tex_step = r->tile_size / r->line.len;
	r->tex_pos = (r->line.start_y - r->render.res_height / 2 + r->line.len / 2)
		* r->tex_step;
}

static void	determine_texture(t_ray *r, t_img *tex)
{
	if (r->in_map.y - r->pos.y > 0 && r->side == 1)
		*tex = r->render.tex.imgs[EA];
	else if (r->in_map.y - r->pos.y <= 0 && r->side == 1)
		*tex = r->render.tex.imgs[WE];
	else if (r->in_map.x - r->pos.x > 0 && r->side == 0)
		*tex = r->render.tex.imgs[SO];
	else if (r->in_map.x - r->pos.x <= 0 && r->side == 0)
		*tex = r->render.tex.imgs[NO];
}

void	texture(t_ray *r, int x)
{
	int		y;
	int		color;
	t_img	tex;

	y = (int)r->line.start_y;
	tex_setup(r);
	while (y++ < (int)r->line.end_y - 1)
	{
		r->tex_y = (int)r->tex_pos & (r->tile_size - 1);
		r->tex_pos += r->tex_step;
		determine_texture(r, &tex);
		get_color(&tex, r->tex_x, r->tex_y, &color);
		put_color_to_img(&r->render.img, x, y, color);
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr + (y * img->line_len + x * img->bpp / 8)) = color;
}
