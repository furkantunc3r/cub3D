/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:48 by merkol            #+#    #+#             */
/*   Updated: 2023/01/09 16:12:21 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_top_and_bottom(t_game *g)
{
	int	i;
	int	height;

	i = -1;
	height = g->rndr.map.res_height - 1;
	while (*(*(g->rndr.map.map) + (++i)))
		if ((*(*(g->rndr.map.map) + i) != '1') \
			&& !is_white_space(*(*(g->rndr.map.map) + i)))
			exit_error(g, "Map Not Enclosed(TOP)!\n");
	i = -1;
	while (*(*(g->rndr.map.map + height) + (++i)))
		if (*(*(g->rndr.map.map + height) + i) != '1' \
			&& !is_white_space(*(*(g->rndr.map.map + height) + i)))
			exit_error(g, "Map Not Enclosed(BOTTOM)!\n");
}

void	is_enclosed(t_game *g, int line_num)
{
	char	*curr;
	int		i;

	i = 0;
	curr = g->rndr.map.map[line_num];
	while (is_white_space(curr[i]))
		i++;
	while (curr[i])
	{
		if ((i == 0 && curr[i] == '0') || \
			(curr[i + 1] == '\0' && curr[i] == '0'))
			exit_error(g, "Map not enclosed!\n");
		if (curr[i] == '0' && (is_white_space(g->rndr.map.map[line_num + 1][i]) \
			|| is_white_space(g->rndr.map.map[line_num - 1][i])))
			exit_error(g, "Map not enclosed!\n");
		if (curr[i] == '0' \
				&& ((i + 1 > (int)ft_strlen(g->rndr.map.map[line_num + 1])
					|| i + 1 > (int)ft_strlen(g->rndr.map.map[line_num - 1]))
				|| (is_white_space(curr[i - 1])
					|| is_white_space(curr[i + 1]))))
			exit_error(g, "Map not enclosed!\n");
		i++;
	}
}

void	check_columns_rows(t_game *g)
{
	int	i;

	i = -1;
	while (*(g->rndr.map.map + (++i)))
		if (i != 0 && i != g->rndr.map.res_height -1)
			is_enclosed(g, i);
}

void	check_map(t_game *g)
{
	check_top_and_bottom(g);
	check_columns_rows(g);
}
