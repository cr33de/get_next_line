/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:52:26 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/14 09:20:55 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	while ((src[j]) && i + j < n - 1 && n > 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (n < i + j)
		return (n + ft_strlen(src));
	return (i + ft_strlen(src));
}
