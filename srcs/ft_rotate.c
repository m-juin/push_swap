/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/07 16:31:20 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_rotate(t_db_list **lst, char *name)
{
	t_db_list	*tmp;

	if ((*lst)->next == NULL && (*lst)->previous == NULL)
		return ;
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
	ft_putstr_fd(name, 1);
}

void	ft_rotate_ss(t_db_list *lsta, t_db_list *lstb)
{
	ft_rotate(&lsta, "");
	ft_rotate(&lstb, "");
	ft_putstr_fd("rr", 1);
}
