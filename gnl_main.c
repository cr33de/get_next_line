/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:34:53 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/26 10:54:17 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	printf("%s: %s\n",argv[1], line);
	ft_strdel(&line);
	close(fd);
	return (0);
}
