/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:22:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/08 10:29:39 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
	int			pos;
	t_db_list	*tmp;

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
