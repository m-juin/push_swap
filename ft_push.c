/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:26:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/02 10:54:01 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_list **src, t_list **dst, char *name)
{
	if (*src == NULL)
		return ;
	if ((*src)->next != NULL)
		(*src)->next->previous = NULL;
	if ((*dst) == NULL)
	{
		(*dst) = (*src);
		(*dst)->previous = NULL;
		(*src) = (*src)->next;
		(*dst)->next = NULL;
		ft_putstr(name);
		return ;
	}
	(*dst)->previous = *src;
	if ((*src)->next != NULL)
		(*src) = (*src)->next;
	(*dst)->previous->next = *dst;
	(*dst) = (*dst)->previous;
	ft_putstr(name);
}
