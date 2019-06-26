/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:42:44 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/26 14:49:01 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	int		ret;
	char	*lline;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &lline);
		//printf("lline = %s\n", lline);
		ft_putchar(ret);
		free(lline);
	}
}
