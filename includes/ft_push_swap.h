/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:44:16 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/09 10:43:20 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_db_list
{
	struct s_db_list	*previous;
	struct s_db_list	*next;
	int					value;
	int					index;
}	t_db_list;

void		ft_apply_algo(t_db_list **lsta, int count);

/*  ft_push.c  */

void		ft_push(t_db_list **src, t_db_list **dst, char *name);

/*  ft_swap.c  */

void		ft_swap(t_db_list **lst, char *name);
void		ft_swap_ss(t_db_list *lsta, t_db_list *lstb);

/*  ft_rotate.c  */

void		ft_rotate(t_db_list **lst, char *name);
void		ft_rotate_ss(t_db_list *lsta, t_db_list *lstb);

/*  ft_reverse_rotate.c  */

void		ft_reverse_rotate(t_db_list **lst, char *name);
void		ft_reverse_rotate_ss(t_db_list *lsta, t_db_list *lstb);

/*  push_swap_utils.c  */

int			ft_parse_arg(char *arg, t_db_list **lsta);
int			ft_checkorder(t_db_list **lst);
int			ft_check_similar(t_db_list **lsta, t_db_list *checked);
int			ft_isvalidnum(char *str);
int			ft_count(t_db_list *elem, int order);

/*	Movement_utils.c  */

void		ft_putfront_a(t_db_list **lsta, t_db_list *target);
void		ft_putfront_b(t_db_list **lstb, t_db_list *target);

/*  algo_radix.c  */

void		ft_radix_algo(t_db_list **lsta);

/*  lst_utils.c  */

void		ft_setindex(t_db_list *lst);
t_db_list	*lst_db_new(char *data);
int			ft_lst_db_size(t_db_list *lst);
void		lst_db_add_back(t_db_list **lst, t_db_list *new);

/*  algo_utils.c  */
int			ft_getindex(t_db_list *lsta, t_db_list *target);
t_db_list	*ft_getbiggest(t_db_list *lsta);
t_db_list	*ft_getsmallest(t_db_list *lsta);

/*  algo.c  */

void		ft_five_algo(t_db_list **lsta);
void		ft_four_algo(t_db_list **lsta);
void		ft_three_algo(t_db_list **lsta);
void		ft_two_algo(t_db_list **lsta);

/*  algo_radix.c  */

void		ft_radix_algo(t_db_list **lsta);

/*  free.c  */

void		ft_freesplit(char **splitted);
void		ft_free(t_db_list **lst);

#endif