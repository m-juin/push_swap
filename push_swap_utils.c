/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:39:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/28 16:19:26 by mjuin            ###   ########.fr       */
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

int	ft_isvalidnum(char *str)
{
	int	valid;
	int	pos;

	valid = 1;
	pos = 0;
	if (str == NULL)
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

t_db_list	*lst_db_new(char *data)
{
	t_db_list *new;

	if (ft_isvalidnum(data) == -1)
		return (NULL);
	new = malloc(sizeof(t_db_list));
	if (!new)
		return (NULL);
	new->previous = NULL;
	new->next = NULL;
	new->value = ft_atoi(data);
	return (new);
}

void	lst_db_add_back(t_db_list **lst, t_db_list *new)
{
	t_db_list *tmp;

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

int	ft_parse_arg(char *arg, t_db_list **lsta)
{
	char 	**splitted;
	t_db_list	*new;
	int		pos;

	splitted = ft_split(arg, ' ');
	pos = 0;
	while (splitted && splitted[pos])
	{
		new = lst_db_new(splitted[pos]);
		if (new == NULL)
			return (-1);
		lst_db_add_back(lsta, new);
		pos++;
	}
	return (1);
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

void lst_print(t_db_list **lst)
{
	t_db_list *tmp;

	tmp = (*lst);

	while ((*lst) != NULL)
	{
		ft_printf("%i\n", (*lst)->value);
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
