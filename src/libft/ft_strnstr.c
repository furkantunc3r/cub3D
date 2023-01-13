/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:11:46 by merkol            #+#    #+#             */
/*   Updated: 2022/02/05 17:11:40 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	size;
	unsigned int	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	size = ft_strlen(needle);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*haystack && haystack[i] == needle[i] && len > i)
		{
			if (i + 1 == size)
				return ((char *)haystack);
			i++;
		}
		haystack++;
		len--;
	}
	return (0);
}
