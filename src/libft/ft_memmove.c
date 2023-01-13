/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:47:18 by merkol            #+#    #+#             */
/*   Updated: 2022/02/18 11:37:47 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_char;
	unsigned char	*temp;
	int				i;

	i = (int)len;
	temp = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	if (dest_char > temp)
	{
		while (--i >= 0)
			dest_char[i] = temp[i];
	}
	else
		ft_memcpy(dest_char, temp, len);
	return (dest_char);
}
