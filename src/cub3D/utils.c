/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:08:01 by merkol            #+#    #+#             */
/*   Updated: 2023/01/10 17:07:29 by merkol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief kaynak array hedef in sonuna eklenir ve kaynak serbest bırakılır.
 * 
 * @param dst kaynak dizinin ekleneceği matris
 * @param src eklenecek dizi
 * @param size_dst hedef çift boyutlu arrayin üye sayısı = dbl_array_size()
 */
void	ft_array_join(t_game *g, char ***dst, char *src)
{
	char	**new;
	int		i;
	int		size_dst;

	i = -1;
	size_dst = dbl_array_size(*dst);
	if (!src)
		return ;
	new = (char **)malloc(sizeof(char *) * (size_dst + 2));
	if (!new)
		exit_error(g, "allocation error!");
	while (++i < size_dst)
		*(new + i) = ft_strdup(*(*dst + i));
	*(new + i++) = ft_strdup(src);
	*(new + i) = NULL;
	if (*dst)
		free_dbl_arry(*dst);
	free(src);
	*dst = new;
}

int	print_dbl_arry(char **arr, char sep)
{
	int	i;

	i = -1;
	if (!arr)
		return (0);
	while (*(arr + ++i))
		printf("%s%c", *(arr + i), sep);
	return (i);
}

int	free_dbl_arry(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = -1;
	while (*(arr + ++i))
		free(*(arr + i));
	free(arr);
	return (i);
}

int	dbl_array_size(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
