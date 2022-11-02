/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/02 10:49:43 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static void lst_print(t_list **lst)
{
	t_list *tmp;

	tmp = (*lst);

	while ((*lst) != NULL)
	{
		printf("%i\n", (*lst)->value);
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}

void ft_algo(t_list *lst)
{
	t_list *lstb;

	lstb = NULL;

	while (ft_checkorder(&lst) == -1)
	{
		if (lst->value > lst->next->value)
		{
			ft_rotate(&lst, "ra\n");
		}
		else
		{
			ft_push(&lst, &lstb, "pa\n");
		}
		if ((lstb != NULL && lstb->next != NULL) && lstb->value > lstb->next->value)
			ft_rotate(&lstb, "rb\n");
		else 
			ft_push(&lstb, &lst, "pb\n");
	}
}

int	main(int ac, char **av)
{
	int	argpos;
	t_list *lsta;

	lsta = NULL;
	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	argpos = 0;
	while (argpos < ac - 1)
	{
		if (ft_check_arg(av[argpos + 1]) == -1)
		{
			ft_putstr("Error\n");
			return (0);	
		}
		argpos++;
	}
	argpos = 0;
	while (argpos < ac - 1)
	{
		lst_db_add_back(&lsta, lst_db_new(ft_atoi(av[argpos + 1])));
		argpos++;
	}
	ft_algo(lsta);
	lst_print(&lsta);
}
