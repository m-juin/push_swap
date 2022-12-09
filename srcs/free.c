/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:42:18 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/09 10:43:31 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_freesplit(char **splitted)
{
	int	pos;

	pos = 0;
	if (splitted == NULL)
		return ;
	while (splitted[pos] != NULL)
	{
		free(splitted[pos]);
		pos++;
	}
	free(splitted);
}

void	ft_free(t_db_list **lst)
{
	t_db_list	*tmp;

	while (lst != NULL && (*lst) != NULL)
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}
