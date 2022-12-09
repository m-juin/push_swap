/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:26:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/07 16:31:22 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_push(t_db_list **src, t_db_list **dst, char *name)
{
	if (*src == NULL)
		return ;
	if ((*src)->next != NULL)
		(*src)->next->previous = NULL;
	if ((*dst) == NULL)
	{
		(*dst) = (*src);
		(*dst)->previous = NULL;
		(*src) = (*src)->next;
		(*dst)->next = NULL;
		ft_putstr_fd(name, 1);
		return ;
	}
	(*dst)->previous = *src;
	(*src) = (*src)->next;
	(*dst)->previous->next = *dst;
	(*dst) = (*dst)->previous;
	ft_putstr_fd(name, 1);
}
