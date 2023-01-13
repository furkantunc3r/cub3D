/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:09:59 by merkol            #+#    #+#             */
/*   Updated: 2022/02/15 16:15:32 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*ns;

	i = 0;
	c %= 256;
	ns = (unsigned char *)s;
	while (ns[i] != '\0' && ns[i] != c)
		i++;
	if (ns[i] == c)
		return ((char *)&ns[i]);
	return ("");
}
