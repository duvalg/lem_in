/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:24:24 by gduval            #+#    #+#             */
/*   Updated: 2016/11/16 14:40:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
		i++;
	if ((dup = (char *)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (src[i] != '\0')
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = src[i];
		return (dup);
	}
	return (NULL);
}
