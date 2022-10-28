/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/28 15:31:46 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

int	main(void)
{
	t_list *lst;
	t_list *lst2;

	lst = lst_db_new(10);
	lst->next = lst_db_new(5);
	lst->next->next = lst_db_new(-5);
	lst->next->next->next = lst_db_new(0);
	lst->next->next->next->next = lst_db_new(-10);
	lst2 = lst_db_new(100);
	lst2->next = lst_db_new(50);
	lst2->next->next = lst_db_new(-50);
	lst2->next->next->next = lst_db_new(25);
	lst2->next->next->next->next = lst_db_new(-100);

	while (lst->next != NULL)
	{
		printf("%i\n", lst->value);
		lst->next->previous = lst;
		lst = lst->next;
	}
	printf("%i\n", lst->value);
	while (lst->previous != NULL)
		lst = lst->previous;
	ft_push(&lst, &lst2, "pa\n");
	printf("\n----------LST------------\n\n");
	while (lst->next != NULL)
	{
		printf("%i\n", lst->value);
		lst = lst->next;
	}
	printf("%i\n", lst->value);
	printf("\n----------LST2------------\n\n");
	while (lst2->next != NULL)
	{
		printf("%i\n", lst2->value);
		lst2 = lst2->next;
	}
	printf("%i\n", lst2->value);
}
