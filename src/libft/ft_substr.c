/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:13:04 by merkol            #+#    #+#             */
/*   Updated: 2022/02/18 15:01:52 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	char			*new;
	unsigned long	strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen || len == 0 || strlen == 0)
		return (ft_strdup(""));
	if (strlen - start >= len)
		new = (char *)malloc(sizeof(char) * (len) + 1);
	else
		new = (char *)malloc(sizeof(char) * (strlen - start + 1));
	if (!new)
		return (NULL);
	while (i < len && s[start] != '\0')
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
