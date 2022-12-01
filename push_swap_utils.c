/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:39:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/01 15:32:28 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_isvalidnum(char *str)
{
	int	valid;
	int	pos;

	valid = 1;
	pos = 0;
	if (str == NULL)
		return (-1);
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	while(str[pos] == '0')
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
	if (value < INT_MIN || value >INT_MAX)
	{
		free(new);
		return (NULL);
	}
	new->value = value;
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

int	ft_check_similar(t_db_list **lsta, t_db_list *checked)
{
	t_db_list *tmp;

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
	char 	**splitted;
	t_db_list	*new;
	int		pos;

	splitted = ft_split(arg, ' ');
	pos = 0;
	while (splitted && splitted[pos])
	{
		new = lst_db_new(splitted[pos]);
		if (new == NULL || ft_check_similar(lsta, new) == -1)
			return (-1);
		lst_db_add_back(lsta, new);
		pos++;
	}
	if (pos == 0)
		return (-1);
	return (pos);
}

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
