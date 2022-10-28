/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:26:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/28 15:30:51 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_list **src, t_list **dst, char *name)
{
	if (*src == NULL)
		return ;
	(*src)->next->previous = NULL;
	(*dst)->previous = *src;
	(*src) = (*src)->next;
	(*dst)->previous->next = *dst;
	(*dst) = (*dst)->previous;
	ft_putstr(name);
}
