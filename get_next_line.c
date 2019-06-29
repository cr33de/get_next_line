/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:54:12 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/29 13:26:22 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

static int			copyline(char *line, char *buf)
{
	unsigned int	count;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (ft_strlen(line) > count + 1)
	{
		buf = ft_strcpy(buf, &(line[count + 1]));
	}
	line[count] = '\0';
	return (1);
}

static int			do_line(const int fd, char **line, char **buff)
{
	char			*temp;
	int				val;

	val = 1;
	while (!(ft_strchr(*line, '\n')) &&
			(val = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		temp = *line;
		*line = ft_strjoin(*line, buff[fd]);
		free(temp);
		if (!*line)
			return (-1);
		ft_bzero(buff[fd], BUFF_SIZE);
	}
	if (*line[0] != '\0' && val >= 0)
		return (copyline(*line, buff[fd]));
	return (val);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buff[BUFF_SIZE];

	if (fd < 0 || !line || fd > BUFF_SIZE || read(fd, buff[fd], 0) < 0 ||
		!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!buff[fd])
		buff[fd] = ft_strnew(BUFF_SIZE + 1);
	if (buff[fd][0] != '\0')
		*line = ft_strcpy(*line, buff[fd]);
	ft_bzero(buff[fd], BUFF_SIZE);
	return (do_line(fd, line, buff));
}
