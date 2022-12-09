/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/08 10:25:03 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_putfront_a(t_db_list **lsta, t_db_list *target)
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

void	ft_putfront_b(t_db_list **lstb, t_db_list *target)
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
