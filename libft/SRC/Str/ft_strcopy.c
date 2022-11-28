/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:22:27 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/08 21:25:26 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strcopy(char *dst, char *src)
{
	char	*tmp;

	tmp = ft_strjoin(dst, src);
	free(dst);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
