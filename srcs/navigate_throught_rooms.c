/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_throught_rooms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:33:17 by gduval            #+#    #+#             */
/*   Updated: 2017/09/12 12:33:18 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room				*find_room_by_name(char **name, t_dna *dna)
{
	short int		i;

	i = -1;
	while (++i < (unsigned short)dna->rooms_nb)
	{
		if (ft_strlen(dna->rooms[i].name) == ft_strlen(*name))
		{
			if (!ft_strcmp(dna->rooms[i].name, *name))
				return (&dna->rooms[i]);
		}
	}
	error();
	return (0);
}

void				check_double(t_dna *dna)
{
	short int		i;
	short int		j;
	char			*name;

	i = -1;
	name = NULL;
	while (++i < (unsigned short)dna->rooms_nb)
	{
		j = -1;
		name = dna->rooms[i].name;
		while (++j < (unsigned short)dna->rooms_nb)
		{
			if (i != j)
				if (!ft_strcmp(dna->rooms[j].name, name))
					if (ft_strlen(dna->rooms[j].name) == ft_strlen(name))
						error();
		}
	}
}
