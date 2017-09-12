/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legb83 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:10:46 by legb83            #+#    #+#             */
/*   Updated: 2016/11/25 16:53:26 by legb83           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_intlen_base(uintmax_t n, int base)
{
	uintmax_t	len;
	uintmax_t	tmp;

	len = 1;
	tmp = n;
	while (tmp >= (uintmax_t)base)
	{
		tmp /= base;
		len++;
	}
	return (len);
}
