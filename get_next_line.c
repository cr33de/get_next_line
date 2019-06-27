/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:54:12 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/27 15:36:59 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

static char		*do_line(int const fd, char *buf, int *ret)
{
	char		cmp[BUFF_SIZE + 1];
	char		*up;

	*ret = read(fd, cmp, BUFF_SIZE);
	if (*ret < BUFF_SIZE && cmp[*ret - 1] != '\n')
	{
		cmp[*ret] = '\n';
		cmp[*ret++] = '\0';
	}
	else
		cmp[*ret] = '\0';
	up = buf;
	buf = ft_strjoin(buf, cmp);
	ft_strdel(&up);
	return (buf);
}

int				get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	int			i;
	char		*str;

	if (!line || fd < 0)
		return (-1);
	i = 1;
	if (!buf)
		buf = ft_strnew(0);
	while (i > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = 0;
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		buf = do_line(fd, buf, &i);
		line = ft_strchr(**fd, '\n');
	}
	if (i == 0)
		*line = ft_strnew(0);
	return (i);
}
