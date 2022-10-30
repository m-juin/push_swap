/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/30 18:57:27 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

int	main(void)
{
	t_list *lst;

	lst = lst_db_new(10);
	lst->next = lst_db_new(5);
	lst->next->next = lst_db_new(-5);
	lst->next->next->next = lst_db_new(0);
	lst->next->next->next->next = lst_db_new(-10);
	while (lst->next != NULL)
	{
		printf("%i\n", lst->value);
		lst->next->previous = lst;
		lst = lst->next;
	}
	printf("%i\n", lst->value);
	while (lst->previous != NULL)
		lst = lst->previous;
	printf("\n-------------------------\n\n");
	ft_rotate(&lst, "ra\n");
	printf("\n-------------------------\n\n");
	while (lst->next != NULL)
	{
		printf("%i\n", lst->value);
		lst = lst->next;
	}
	printf("%i\n", lst->value);
}
