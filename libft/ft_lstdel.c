/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdomingo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:54:38 by rdomingo          #+#    #+#             */
/*   Updated: 2019/06/09 15:25:18 by rdomingo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next;

	tmp = *alst;
	if (del != NULL)
	{
		while (tmp != NULL)
		{
			next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next;
		}
		*alst = NULL;
	}
}
