/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:44:16 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/28 15:28:05 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				value;
}	t_list;

void	ft_putstr(char *str);
void	swap(t_list **lst, char *name);
void	swap_ss(t_list *lsta, t_list *lstb);
void	ft_push(t_list **src, t_list **dst, char *name);
t_list	*lst_db_new(int data);
