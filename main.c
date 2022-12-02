/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/02 14:38:21 by mjuin            ###   ########.fr       */
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
	else if (lst->next->value > lst->next->next->value &&
		lst->value < lst->next->next->value)
	{
		ft_reverse_rotate(lsta, "rra\n");
		ft_apply_algo(lsta, 2);
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

t_db_list	*ft_getbiggest(t_db_list *lsta)
{
	t_db_list	*max;

	max = NULL;
	while (lsta != NULL)
	{
		if (max == NULL || max->value < lsta->value)
			max = lsta;
		lsta = lsta->next;
	}
	return (max);
}

int	ft_getindex(t_db_list *lsta, t_db_list *target)
{
	int	pos;
	t_db_list *tmp;

	pos = 0;
	tmp = lsta;
	while (lsta != target)
	{
		pos++;
		lsta = lsta->next;
	}
	return (pos);
	lsta = tmp;
}

void ft_putfront_a(t_db_list **lsta, t_db_list *target)
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

void ft_putfront_b(t_db_list **lstb, t_db_list *target)
{
	int	smallestpos;
	int	listsize;

	smallestpos = ft_getindex((*lstb), target);
	listsize = ft_lst_db_size((*lstb));
	if (smallestpos <= listsize / 2)
		while ((*lstb) != target)
			ft_rotate(lstb, "rb\n");
	else
		while ((*lstb) != target)
			ft_reverse_rotate(lstb, "rrb\n");
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

void ft_putfclosest(t_db_list **lst, t_db_list *small, t_db_list *big, int count)
{
	int smallcount;
	int	bigcount;

	if (big == small)
	{
		ft_putfront_a(lst, big);
		return ;
	}
	smallcount = ft_getindex((*lst), small);
	if (smallcount > count - smallcount)
		smallcount = count - smallcount;
	bigcount = ft_getindex((*lst), big);
	if (bigcount > count - bigcount)
		bigcount = count - bigcount;
	if (bigcount <= smallcount)
		ft_putfront_a(lst, big);
	else
		ft_putfront_a(lst, small);
}

t_db_list *ft_getclosest(t_db_list *lst, t_db_list *target)
{
	t_db_list *closest;
	t_db_list	*tmp;

	closest = NULL;
	tmp = lst;
	while (lst != NULL)
	{
		if (lst->value < target->value)
		{
			if (closest == NULL || lst->value > closest->value )
				closest = lst;
		}
		lst = lst->next;
	}
	if (closest == NULL)
	{
		return (tmp);
	}
	return (closest);
}

void ft_ultim_algo(t_db_list **lsta, int count)
{
	t_db_list	*lstb;
	t_db_list	*smallest;
	t_db_list	*biggest;
	
	lstb = NULL;
	while ((*lsta) != NULL)
	{
		smallest = ft_getsmallest((*lsta));
		biggest = ft_getbiggest((*lsta));
		ft_putfclosest(lsta, smallest, biggest, count);
		ft_putfront_b(&lstb, ft_getclosest(lstb, (*lsta)));
		ft_push(lsta, &lstb, "pb\n");
		if (lstb->next != NULL && lstb->value < lstb->next->value)
			ft_rotate(&lstb, "rb\n");
		count -= 1;
	}
	while (lstb != NULL)
	{
		biggest = ft_getbiggest(lstb);
		ft_putfront_b(&lstb, biggest);
		ft_push(&lstb, lsta, "pa\n");
		count += 1;
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
	else
		ft_ultim_algo(lsta, count);
}

int	main(int ac, char **av)
{
	int			argpos;
	int			valid;
	int			argcount;
	t_db_list	*lsta;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
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
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		argcount += valid;
		argpos++;
	}
	/*ft_printf("\n ---------------------\n         Base\n ---------------------\n\n");
	lst_print(&lsta);
	ft_printf("\n ---------------------\n");
	ft_printf("        Resolve ");
	ft_printf("\n ---------------------\n\n");*/
	ft_apply_algo(&lsta, argcount);
	/*ft_printf("\n ---------------------\n\n");
	lst_print(&lsta);*/
}
