/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:21 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/14 10:02:01 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = ft_strlen(needle);
	j = ft_strlen(haystack);
	while (haystack && i <= j)
	{
		if (!ft_strncmp(haystack, needle, i))
			return ((char *)haystack);
		++haystack;
		--j;
	}
	return (NULL);
}
