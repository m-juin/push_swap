/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:39:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/31 10:54:12 by mjuin            ###   ########.fr       */
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

void	lst_db_add_back(t_list **lst, t_list *new)
{
	t_list *tmp;

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

int	ft_check_arg(char *arg)
{
	int	pos;

	pos = 0;
	if (arg[pos] == '-')
		pos++;
	while (arg[pos] >= '0' && arg[pos] <= '9')
		pos++;
	if (arg[pos] == '\0')
		return (1);
	return (-1);
}

int	ft_atoi(char *str)
{
	int ret;
	int	pos;
	int	sign;

	ret = 0;
	pos = 0;
	sign = 1;
	if (str[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		ret = ((ret * 10) + (str[pos] - '0'));
		pos++;
	}
	if (str[pos] == '\0')
		return (ret * sign);
	return (-1);
}
