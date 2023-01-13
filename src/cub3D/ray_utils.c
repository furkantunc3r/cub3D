/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:53 by merkol            #+#    #+#             */
/*   Updated: 2023/01/12 12:59:04 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//draw utils
void	get_color(t_img *img, int x, int y, int *color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*color = *(unsigned int *)dst;
}

void	put_color_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_point	assign_point(double x, double y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_line	init_line(double start_x, double start_y, double angle, double len)
{
	t_line	line;

	line.start_x = start_x;
	line.start_y = start_y;
	line.angle = angle;
	line.end_x = start_x + len * cos(angle);
	line.end_y = start_y + len * sin(angle);
	return (line);
}

void	init_direction(t_game *g, char start)
{
	g->ray.plane = assign_point(0, 0);
	g->ray.direction = assign_point(0, 0);
	if (start == 'W')
	{
		g->ray.direction.x = -g->ray.fov;
		g->ray.plane.y = g->ray.fov;
	}
	else if (start == 'E')
	{
		g->ray.direction.x = g->ray.fov;
		g->ray.plane.y = -g->ray.fov;
	}
	else if (start == 'S')
	{
		g->ray.direction.y = g->ray.fov;
		g->ray.plane.x = g->ray.fov;
	}
	else if (start == 'N')
	{
		g->ray.direction.y = -g->ray.fov;
		g->ray.plane.x = -g->ray.fov;
	}
}
