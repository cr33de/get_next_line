/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:27:35 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/09 15:13:03 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char		i;
	char		*t;

	t = NULL;
	i = (char)c;
	while (*s)
	{
		if (*s == i)
			t = (char*)s;
		s++;
	}
	if (*s == i)
		return ((char *)s);
	return (t);
}
