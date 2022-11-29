/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/29 14:22:24 by mjuin            ###   ########.fr       */
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
	t_db_list *lst;

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
	else
		ft_reverse_rotate(lsta, "rra\n");
}

t_db_list	*ft_getsmallest(t_db_list *lsta)
{
	t_db_list *min;

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
	int pos;

	pos = 0;
	while (lsta != target)
	{
		pos++;
		lsta = lsta->next;
	}
	return(pos);
}

void	ft_four_algo(t_db_list **lsta)
{
	t_db_list	*smallest;
	t_db_list	*lstb;
	int			smallestpos;

	smallest = ft_getsmallest((*lsta));
	smallestpos = ft_getindex((*lsta), smallest);
	if (smallestpos <= 1)
		while ((*lsta) != smallest)
			ft_rotate(lsta, "ra\n");
	else
		while ((*lsta) != smallest)
			ft_reverse_rotate(lsta, "ra\n");
	lstb = NULL;
	ft_push(lsta, &lstb, "pb\n");
	ft_three_algo(lsta);
	ft_push(&lstb, lsta, "pa\n");
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
}

int	main(int ac, char **av)
{
	int	argpos;
	int	valid;
	int	argcount;
	t_db_list *lsta;

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
	//ft_printf("\n ---------------------\n     Three solving\n ---------------------\n\n");
	//lst_print(&lsta);
	//ft_printf("\n ---------------------\n");
	//ft_printf("        Resolve ");
	//ft_printf("\n ---------------------\n\n");
	ft_apply_algo(&lsta, argcount);
	//ft_printf("\n ---------------------\n\n");
	//lst_print(&lsta);
	//ft_printf("\n");
}
