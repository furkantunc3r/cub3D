/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:20:32 by merkol            #+#    #+#             */
/*   Updated: 2022/02/13 12:17:09 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (0);
	ft_memcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
