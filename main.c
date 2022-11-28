/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/28 16:22:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

/*void ft_algo(t_db_list *lst, int quantity)
{
	t_db_list *lstb;

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
}*/

int	main(int ac, char **av)
{
	int	argpos;
	int	valid;
	t_db_list *lsta;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	argpos = 1;
	while (argpos < ac)
	{
		valid = ft_parse_arg(av[argpos], &lsta);
		if (valid == -1)
			ft_putstr("Error\n");
		argpos++;
	}
	lst_print(&lsta);
}
