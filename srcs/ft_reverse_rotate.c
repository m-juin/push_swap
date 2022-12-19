/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/16 10:05:22 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_reverse_rotate(t_db_list **lst, char *name)
{
	t_db_list	*tmp;

	tmp = (*lst);
	while ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
	}
	tmp->previous = (*lst);
	(*lst)->next = tmp;
	(*lst)->previous->next = NULL;
	(*lst)->previous = NULL;
	ft_putstr_fd(name, 1);
}

void	ft_reverse_rotate_ss(t_db_list *lsta, t_db_list *lstb)
{
	ft_reverse_rotate(&lsta, "");
	ft_reverse_rotate(&lstb, "");
	ft_putstr_fd("rrr\n", 1);
}
