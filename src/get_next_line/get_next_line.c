/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:04:43 by merkol            #+#    #+#             */
/*   Updated: 2022/03/01 13:04:46 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_read(int fd, char *mystr)
{
	char	*buff;
	int		ret;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_get_strchr(mystr, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			mystr = ft_get_strjoin(mystr, buff);
		}
	}
	free(buff);
	return (mystr);
}

char	*ft_line(char *mystr)
{
	char	*line;
	int		i;

	i = 0;
	if (!mystr[i])
		return (NULL);
	while (mystr[i] && mystr[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (mystr[i] && mystr[i] != '\n' )
	{
		line[i] = mystr[i];
		i++;
	}
	if (mystr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_newstr(char *mystr)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	while (mystr[i] && mystr[i] != '\n')
		i++;
	if (!mystr[i])
	{
		free(mystr);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(mystr) - i + 1));
	if (!newstr)
		return (NULL);
	j = 0;
	while (mystr[i++])
		newstr[j++] = mystr[i];
	newstr[j] = '\0';
	free(mystr);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*mystr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mystr = ft_read(fd, mystr);
	if (!mystr)
		return (NULL);
	line = ft_line(mystr);
	mystr = ft_newstr(mystr);
	return (line);
}
