/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:06:31 by merkol            #+#    #+#             */
/*   Updated: 2023/01/12 14:14:26 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_step_and_dist(t_ray *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (r->pos.x - r->in_map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->in_map.x + 1 - r->pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (r->pos.y - r->in_map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->in_map.y + 1 - r->pos.y) * r->delta_dist.y;
	}
}

void	dda(t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->in_map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->in_map.y += r->step.y;
			r->side = 1;
		}
		if (r->map[(int)r->in_map.y][(int)r->in_map.x] == '1')
			r->hit = 1;
	}
}

void	check_limit(t_ray *r)
{
	if (r->line.start_x < 0)
	{
		r->line.start_x = 0;
		r->line.end_x = 0;
	}
	if (r->line.start_x > r->render.res_width)
	{
		r->line.start_x = r->render.res_width;
		r->line.end_x = r->render.res_width;
	}
	if (r->line.start_y < 0)
		r->line.start_y = 0;
	if (r->line.end_y < 0)
		r->line.end_y = 0;
	if (r->line.end_y > r->render.res_height)
		r->line.end_y = r->render.res_height;
	if (r->line.start_y > r->render.res_height)
		r->line.start_y = r->render.res_height;
}

void	distance_and_line(t_ray *r, int x)
{
	int		h;
	double	line_height;

	h = r->render.res_height;
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist.x - r->delta_dist.x;
	else
		r->perp_wall_dist = r->side_dist.y - r->delta_dist.y;
	line_height = (int)(h / r->perp_wall_dist);
	r->line.len = line_height;
	r->line.start_x = x;
	r->line.start_y = -line_height / 2 + h / 2;
	r->line.end_x = x;
	r->line.end_y = line_height / 2 + h / 2;
	r->line.delta.x = sign(r->line.end_x - r->line.start_x);
	r->line.delta.y = sign(r->line.end_y - r->line.start_y);
	check_limit(r);
}

void	raycaster(t_ray *r)
{
	int	i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		setup_ray(r, i);
		ray_step_and_dist(r);
		dda(r);
		distance_and_line(r, i);
		texture(r, i);
	}
	r->player.x = r->pos.x * r->tile_size;
	r->player.y = r->pos.y * r->tile_size;
}
