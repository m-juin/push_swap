/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:44:05 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/12 11:54:43 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_apply_algo(t_db_list **lsta, int count)
{
	if (ft_checkorder(lsta) == 1)
	{
		ft_free(lsta);
		return ;
	}
	else if (count == 2)
		ft_two_algo(lsta);
	else if (count == 3)
		ft_three_algo(lsta);
	else if (count == 4)
		ft_four_algo(lsta);
	else if (count == 5)
		ft_five_algo(lsta);
	else
		ft_radix_algo(lsta);
	ft_free(lsta);
}

int	main(int ac, char **av)
{
	int			argpos;
	int			valid;
	int			argcount;
	t_db_list	*lsta;

	if (ac < 2)
		return (0);
	argpos = 0;
	argcount = 0;
	lsta = NULL;
	while (++argpos < ac)
	{
		valid = ft_parse_arg(av[argpos], &lsta);
		if (valid == -1)
		{
			ft_free(&lsta);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		argcount += valid;
	}
	ft_apply_algo(&lsta, argcount);
}
