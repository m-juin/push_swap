/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:39:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/09 10:42:39 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_isvalidnum(char *str)
{
	int	pos;

	pos = 0;
	if (str == NULL)
		return (-1);
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	while (str[pos] == '0')
		pos++;
	if (ft_strlen(str) - pos > 11)
		return (-1);
	while (str[pos])
	{
		if (pos == 0 && (str[pos] == '-' || str[pos] == '+'))
			pos++;
		else if (str[pos] >= '0' && str[pos] <= '9')
			pos++;
		else
			return (-1);
	}
	if (pos == 0 || str[pos -1] == '-' || str[pos -1] == '+')
		return (-1);
	return (1);
}

int	ft_check_similar(t_db_list **lsta, t_db_list *checked)
{
	t_db_list	*tmp;

	tmp = (*lsta);
	while ((*lsta) != NULL)
	{
		if ((*lsta)->value == checked->value)
			return (-1);
		(*lsta) = (*lsta)->next;
	}
	(*lsta) = tmp;
	return (1);
}

int	ft_parse_arg(char *arg, t_db_list **lsta)
{
	char		**splitted;
	t_db_list	*new;
	int			pos;

	splitted = ft_split(arg, ' ');
	pos = 0;
	while (splitted && splitted[pos])
	{
		new = lst_db_new(splitted[pos]);
		if (new == NULL || ft_check_similar(lsta, new) == -1)
		{
			if (new != NULL)
				free(new);
			ft_freesplit(splitted);
			return (-1);
		}
		lst_db_add_back(lsta, new);
		pos++;
	}
	ft_freesplit(splitted);
	if (pos == 0)
		return (-1);
	return (pos);
}

int	ft_checkorder(t_db_list **lst)
{
	t_db_list	*start;

	start = (*lst);
	while ((*lst)->next != NULL)
	{
		if ((*lst)->value > (*lst)->next->value)
		{
			(*lst) = start;
			return (-1);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = start;
	return (1);
}

int	ft_count(t_db_list *elem, int order)
{
	int			count;
	int			value;
	t_db_list	*tmp;

	tmp = elem;
	count = 0;
	value = elem->value;
	while (elem != NULL)
	{
		if (elem->value < value)
			count++;
		if (order == 1)
			elem = elem->next;
		else
			elem = elem->previous;
	}
	elem = tmp;
	return (count);
}
