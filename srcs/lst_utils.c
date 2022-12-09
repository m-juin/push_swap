/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:40:55 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/08 10:29:55 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_lst_db_size(t_db_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_db_list	*lst_db_new(char *data)
{
	t_db_list		*new;
	long long int	value;

	if (ft_isvalidnum(data) == -1)
		return (NULL);
	new = malloc(sizeof(t_db_list));
	if (!new)
		return (NULL);
	new->previous = NULL;
	new->next = NULL;
	value = ft_atoi(data);
	if (value < INT_MIN || value > INT_MAX)
	{
		free(new);
		return (NULL);
	}
	new->index = -1;
	new->value = value;
	return (new);
}

void	lst_db_add_back(t_db_list **lst, t_db_list *new)
{
	t_db_list	*tmp;

	tmp = (*lst);
	if (lst == NULL)
		lst = &new;
	else if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		new->previous = (*lst);
		(*lst) = tmp;
	}
}

void	ft_setindex(t_db_list *lst)
{
	t_db_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		lst->index = ft_count(lst, 1) + ft_count(lst, -1);
		lst = lst->next;
	}
	lst = tmp;
}
