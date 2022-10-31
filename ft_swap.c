/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:17:49 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/30 18:59:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list **lst, char *name)
{
	if ((*lst)->next != NULL && (*lst) != NULL)
	{
		(*lst)->previous = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		(*lst)->previous->previous = NULL;
		(*lst)->previous->next = (*lst);
		*lst = (*lst)->previous;
		ft_putstr(name);
	}
}

void	ft_swap_ss(t_list *lsta, t_list *lstb)
{
	swap(&lsta, "");
	swap(&lstb, "");
	ft_putstr("ss"\n);
}