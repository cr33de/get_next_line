/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:57:18 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/14 09:11:12 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	long			sign;
	unsigned long	num;
	unsigned int	i;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f')
		++str;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return ((int)(num * sign));
}
