/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:28:01 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/08 10:21:10 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_two_algo(t_db_list **lsta)
{
	if (ft_checkorder(lsta) == -1)
		ft_swap(lsta, "sa\n");
}

void	ft_three_algo(t_db_list **lsta)
{
	t_db_list	*lst;

	lst = (*lsta);
	if (lst->value > lst->next->value && lst->value < lst->next->next->value)
		ft_swap(lsta, "sa\n");
	else if (lst->value > lst->next->value
		&& lst->next->value > lst->next->next->value)
	{
		ft_swap(lsta, "sa\n");
		ft_reverse_rotate(lsta, "rra\n");
	}
	else if (lst->value > lst->next->value)
	{
		ft_reverse_rotate(lsta, "rra\n");
		ft_reverse_rotate(lsta, "rra\n");
	}
	else if (lst->next->value > lst->next->next->value
		&& lst->value < lst->next->next->value)
	{
		ft_reverse_rotate(lsta, "rra\n");
		ft_apply_algo(lsta, 2);
	}
	else
		ft_reverse_rotate(lsta, "rra\n");
}

void	ft_four_algo(t_db_list **lsta)
{
	t_db_list	*smallest;
	t_db_list	*lstb;

	smallest = ft_getsmallest((*lsta));
	ft_putfront_a(lsta, smallest);
	lstb = NULL;
	ft_push(lsta, &lstb, "pb\n");
	ft_three_algo(lsta);
	ft_push(&lstb, lsta, "pa\n");
}

void	ft_five_algo(t_db_list **lsta)
{
	t_db_list	*smallest;
	t_db_list	*lstb;

	smallest = ft_getsmallest((*lsta));
	ft_putfront_a(lsta, smallest);
	lstb = NULL;
	ft_push(lsta, &lstb, "pb\n");
	smallest = ft_getsmallest((*lsta));
	ft_putfront_a(lsta, smallest);
	ft_push(lsta, &lstb, "pb\n");
	if (ft_checkorder(&lstb) == 1)
		ft_swap(&lstb, "sb\n");
	ft_apply_algo(lsta, 3);
	ft_push(&lstb, lsta, "pa\n");
	ft_push(&lstb, lsta, "pa\n");
}
