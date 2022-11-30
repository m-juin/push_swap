/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/30 13:25:31 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

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
	else if (lst->next->value > lst->next->next->value)
	{
		ft_reverse_rotate(lsta, "rra\n");
		ft_swap(lsta, "sa\n");
	}
	else
		ft_reverse_rotate(lsta, "rra\n");
}

t_db_list	*ft_getsmallest(t_db_list *lsta)
{
	t_db_list	*min;

	min = NULL;
	while (lsta != NULL)
	{
		if (min == NULL || min->value > lsta->value)
			min = lsta;
		lsta = lsta->next;
	}
	return (min);
}

int	ft_getindex(t_db_list *lsta, t_db_list *target)
{
	int	pos;

	pos = 0;
	while (lsta != target)
	{
		pos++;
		lsta = lsta->next;
	}
	return (pos);
}

void ft_putfront(t_db_list **lsta, t_db_list *target)
{
	int	smallestpos;
	int	listsize;

	smallestpos = ft_getindex((*lsta), target);
	listsize = ft_lst_db_size((*lsta));
	if (smallestpos <= listsize / 2)
		while ((*lsta) != target)
			ft_rotate(lsta, "ra\n");
	else
		while ((*lsta) != target)
			ft_reverse_rotate(lsta, "rra\n");
}

void	ft_four_algo(t_db_list **lsta)
{
	t_db_list	*smallest;
	t_db_list	*lstb;

	smallest = ft_getsmallest((*lsta));
	ft_putfront(lsta, smallest);
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
	ft_putfront(lsta, smallest);
	lstb = NULL;
	ft_push(lsta, &lstb, "pb\n");
	smallest = ft_getsmallest((*lsta));
	ft_putfront(lsta, smallest);
	ft_push(lsta, &lstb, "pb\n");
	if (ft_checkorder(&lstb) == 1)
		ft_swap(&lstb, "sb\n");
	ft_three_algo(lsta);
	ft_push(&lstb, lsta, "pa\n");
	ft_push(&lstb, lsta, "pa\n");
}

void	ft_ten_algo(t_db_list **lsta)
{
	int			count;
	t_db_list	*smallest;
	t_db_list	*lstb;

	count = 0;
	lstb = NULL;
	while (count < 5)
	{
		smallest = ft_getsmallest((*lsta));
		ft_putfront(lsta, smallest);
		ft_push(lsta, &lstb, "pb\n");
		count++;
	}
	ft_apply_algo(&lstb, 5);
	ft_apply_algo(lsta, 5);
	count = 0;
	while (count < 5)
	{
		ft_rotate(&lstb, "rb\n");
		ft_push(&lstb, lsta, "pb\n");
		count++;
	}
}

void	ft_apply_algo(t_db_list **lsta, int count)
{
	if (ft_checkorder(lsta) == 1)
		return ;
	else if (count == 2)
		ft_two_algo(lsta);
	else if (count == 3)
		ft_three_algo(lsta);
	else if (count == 4)
		ft_four_algo(lsta);
	else if (count == 5)
		ft_five_algo(lsta);
	else if (count == 10)
		ft_five_algo(lsta);
}

int	main(int ac, char **av)
{
	int			argpos;
	int			valid;
	int			argcount;
	t_db_list	*lsta;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	argpos = 1;
	argcount = 0;
	lsta = NULL;
	while (argpos < ac)
	{
		valid = ft_parse_arg(av[argpos], &lsta);
		if (valid == -1)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		argcount += valid;
		argpos++;
	}
	ft_printf("\n ---------------------\n     Three solving\n ---------------------\n\n");
	lst_print(&lsta);
	ft_printf("\n ---------------------\n");
	ft_printf("        Resolve ");
	ft_printf("\n ---------------------\n\n");
	ft_apply_algo(&lsta, argcount);
	ft_printf("\n ---------------------\n\n");
	lst_print(&lsta);
}
