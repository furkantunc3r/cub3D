/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:21:06 by merkol            #+#    #+#             */
/*   Updated: 2022/02/15 13:00:18 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char	**split(char **s, char *s1, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < ft_count(s1, c))
	{
		while (s1[i] == c)
			i++;
		k = i;
		while (s1[k] != c && s1[k] != '\0')
			k++;
		s[j] = ft_substr(s1, i, (k - i));
		i = k;
		j++;
	}
	s[j] = NULL;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**n;

	if (!s)
		return (NULL);
	n = malloc(sizeof(char *) * ft_count((char *)s, c) + 1);
	if (!n)
		return (NULL);
	n = split(n, (char *)s, c);
	return (n);
}
