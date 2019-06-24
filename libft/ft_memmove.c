/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:49:28 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/11 17:57:04 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		i = n;
		while (i--)
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
	}
	return (dst);
}
