/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:17:02 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/14 09:17:16 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strswd(char const *s, char c)
{
	unsigned int	i;
	int				swd;

	swd = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			swd++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (swd);
}

char				**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**slp;

	i = 0;
	k = 0;
	if (s == NULL || !c)
		return (NULL);
	if (!(slp = (char **)malloc(sizeof(char *) * (ft_strswd(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			slp[k++] = ft_strsub(s, j, i - j);
		}
	}
	slp[k] = NULL;
	return (slp);
}
