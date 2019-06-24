/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:13:06 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/20 08:59:14 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	t;

	t = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == t)
			return (str);
		str++;
	}
	return (NULL);
}
