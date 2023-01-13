/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:05:11 by merkol            #+#    #+#             */
/*   Updated: 2022/03/01 13:05:54 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_get_strjoin(char *mystr, char *buff);
char	*ft_get_strchr(char *s, int c);

#endif
