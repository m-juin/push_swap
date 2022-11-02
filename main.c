/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/01 00:13:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

/*static void lst_print(t_list **lst)
{
	t_list *tmp;

	tmp = (*lst);

	while ((*lst) != NULL)
	{
		printf("%i\n", (*lst)->value);
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}*/

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
	printf("Order = %i\n", ft_checkorder(&lsta));
}
