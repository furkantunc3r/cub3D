/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:14:01 by merkol            #+#    #+#             */
/*   Updated: 2022/02/15 15:02:24 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ns;
	int				a;

	ns = (unsigned char *)s;
	c %= 256;
	a = ft_strlen(s);
	while (a >= 0)
	{
		if (ns[a] == c)
			return ((char *)&ns[a]);
		a--;
	}
	return (0);
}
