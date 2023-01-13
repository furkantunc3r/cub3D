/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:50 by merkol            #+#    #+#             */
/*   Updated: 2023/01/09 16:12:28 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_extension(char *file, char *extension)
{
	int	file_lenght;
	int	extension_lenght;

	file_lenght = ft_strlen(file);
	extension_lenght = ft_strlen(extension);
	if (extension_lenght > file_lenght)
		return (0);
	return (!ft_strcmp(file + file_lenght - extension_lenght, extension));
}

int	open_cub(t_game *g, char *cub)
{
	g->rndr.map.fd_cub = open(cub, O_RDONLY);
	if ((g->rndr.map.fd_cub) == -1)
		exit_error(g, "Cannot Open File!!\n");
	return (0);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}

int	get_longest_row(char **map)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (map[++i])
		if ((int)ft_strlen(map[i]) > ret)
			ret = ft_strlen(map[i]);
	return (ret);
}
