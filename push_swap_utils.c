/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:39:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/28 14:17:08 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		write(0, &str[pos], 1);
		pos++;
	}
}

t_list	*lst_db_new(int data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->previous = NULL;
	new->next = NULL;
	new->value = data;
	return (new);
}
