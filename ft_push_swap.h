/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:44:16 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/28 16:19:49 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_db_list
{
	struct s_db_list	*previous;
	struct s_db_list	*next;
	int				value;
}	t_db_list;

void	ft_putstr(char *str);
int		ft_parse_arg(char *arg, t_db_list **lsta);
void	ft_swap(t_db_list **lst, char *name);
void	ft_swap_ss(t_db_list *lsta, t_db_list *lstb);
void	ft_push(t_db_list **src, t_db_list **dst, char *name);
void	ft_rotate(t_db_list **lst, char *name);
void	ft_rotate_ss(t_db_list *lsta, t_db_list *lstb);
void	ft_reverse_rotate(t_db_list **lst, char *name);
void	ft_reverse_rotate_ss(t_db_list *lsta, t_db_list *lstb);
int		ft_checkorder(t_db_list **lst);
t_db_list	*lst_db_new(char *data);
void	lst_db_add_back(t_db_list **lst, t_db_list *new);
void	lst_print(t_db_list **lst);
