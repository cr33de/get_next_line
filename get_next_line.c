/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:54:12 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/24 14:47:26 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		do_line(const int fd, char **line, char **ret)
{
	char		*temp;
	int			val;

	val = 1;
	while (!(ft_strchr(*line, '\n')) &&
			(val = read(fd, ret[fd], BUFF_SIZE)) > 0)
	{
		temp = *line;
		*line = ft_strjoin(*line, ret[fd]);
		free(temp);
		if (!*line)
			return (-1);
		ft_bzero(ret[fd], BUFF_SIZE);
	}
	if (*line[0] != '\0' && val >= 0)
		return (*ft_strcpy(*line, ret[fd]));
	return (val);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buff = NULL;
	int				ret;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (!buff)
		buff = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')) != NULL)
		{
		*str = 0;
		*line = ft_strdup(buff);
		ft_memmove(buff, str + 1, ft_strlen(str + 1) + 1);
		return (1);
		}
		ret = do_line(fd, line, &ret);
	}
	if (ret == 0)
		*line = ft_strnew(0);
	return (ret);
}

int	main()
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		//printf("line = %s\n" , line);
		ft_putchar(ret);
		free(line);
	}
}
