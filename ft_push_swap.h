/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:44:16 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/30 18:58:40 by mjuin            ###   ########.fr       */
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
void	ft_swap(t_list **lst, char *name);
void	ft_swap_ss(t_list *lsta, t_list *lstb);
void	ft_push(t_list **src, t_list **dst, char *name);
void	ft_rotate(t_list **lst, char *name);
t_list	*lst_db_new(int data);
