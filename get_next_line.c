/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:54:12 by rdomingo          #+#    #+#             */
/*   Updated: 2019/07/04 13:34:02 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

static int		do_line(char **sfd, char **line)
{
	size_t		i;
	char		*temp;

	i = 0;
	while ((*sfd)[i] != '\n' && (*sfd)[i] != '\0')
		i++;
	if ((*sfd)[i] == '\n')
	{
		*line = ft_strsub(*sfd, 0, i);
		temp = ft_strdup(*sfd + i + 1);
		ft_strdel(sfd);
		*sfd = ft_strdup(temp);
		free(temp);
	}
	else if ((*sfd)[i] == '\0')
	{
		*line = ft_strdup(*sfd);
		ft_strdel(sfd);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*s[1024];
	char		*temp;
	int			val;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while (!(ft_strchr(s[fd], '\n')) && (val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[val] = '\0';
		temp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = ft_strdup(temp);
		free(temp);
	}
	if (val < 0)
		return (-1);
	else if (val == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	else
		return (do_line(&s[fd], line));
}
