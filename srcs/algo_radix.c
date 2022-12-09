/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:53:29 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/08 10:23:32 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_pushback(t_db_list **src, t_db_list **dst, char *name)
{
	while ((*src) != NULL)
	{
		ft_push(src, dst, name);
	}
}

static int	ft_getsize(int size)
{
	int	divider;
	int	ret;

	divider = 1;
	ret = 0;
	while (size / divider > 0)
	{
		divider *= 2;
		ret++;
	}
	return (ret);
}

void	ft_radix_algo(t_db_list **lsta)
{
	int			digitcount;
	t_db_list	*lstb;
	int			pos;
	int			pos2;

	ft_setindex((*lsta));
	digitcount = ft_getsize(ft_getbiggest((*lsta))->index);
	pos = 0;
	lstb = NULL;
	while (pos < digitcount)
	{
		pos2 = ft_getbiggest((*lsta))->index;
		while (pos2 >= 0)
		{
			if (((*lsta)->index >> pos) & 1)
				ft_rotate(lsta, "ra\n");
			else
				ft_push(lsta, &lstb, "pb\n");
			pos2--;
		}
		ft_pushback(&lstb, lsta, "pa\n");
		pos++;
	}
}
