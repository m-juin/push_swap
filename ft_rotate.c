/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/30 19:08:10 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_list **lst, char *name)
{
	t_list	*tmp;

	tmp = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->previous = NULL;
	while ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
	}
	tmp->previous = (*lst);
	(*lst)->next = tmp;
	(*lst) = tmp->next;
	tmp->next = NULL;
	ft_putstr(name);
}

void	ft_rotate_ss(t_list *lsta, t_list *lstb)
{
	ft_rotate(lsta, "");
	ft_rotate(lstb, "");
	ft_putstr("rr");
}
