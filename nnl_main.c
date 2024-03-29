/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:06:25 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/26 12:45:59 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 2)
		{
			while ((ret = get_next_line(fd, &line)) > 0)
				if (line)
				{
					printf("%s\n", line);
					ft_strdel(&line);
				}
		}
		if (line)
			ft_strdel(&line);
		close(fd);
	}
	sleep(45);
	return (0);
}
