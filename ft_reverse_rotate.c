/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/30 23:04:10 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_reverse_rotate(t_list **lst, char *name)
{
	t_list	*tmp;

	tmp = (*lst);
	while ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
	}
	tmp->previous = (*lst);
	(*lst)->next = tmp;
	(*lst)->previous->next = NULL;
	(*lst)->previous = NULL;
	ft_putstr(name);
}

void	ft_reverse_rotate_ss(t_list *lsta, t_list *lstb)
{
	ft_reverse_rotate(&lsta, "");
	ft_reverse_rotate(&lstb, "");
	ft_putstr("rrr :");
}
