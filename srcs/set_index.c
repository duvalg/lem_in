/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:33:17 by gduval            #+#    #+#             */
/*   Updated: 2017/09/12 12:33:18 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			check_room(t_room *room, short int index)
{
	if (room->index == -1)
	{
		if (room)
			room->index = index + 1;
	}
}

static int			links_broken(short int index, t_dna *dna)
{
	int				i;

	i = -1;
	while (++i < dna->rooms_nb)
	{
		if (dna->rooms[i].index == index - 1)
			return (0);
	}
	return (1);
}

int					check_links(char **name, short int index, t_dna *dna)
{
	t_links			*tmp;

	tmp = dna->links;
	while (tmp->next != NULL)
	{
		if (!ft_strcmp(*name, tmp->link_a))
		{
			if (ft_strlen(*name) == ft_strlen(tmp->link_a))
				check_room(find_room_by_name(&tmp->link_b, dna), index);
		}
		else if (!ft_strcmp(*name, tmp->link_b))
		{
			if (ft_strlen(*name) == ft_strlen(tmp->link_b))
				check_room(find_room_by_name(&tmp->link_a, dna), index);
		}
		tmp = tmp->next;
	}
	return (1);
}

void				set_index(t_dna *dna)
{
	int			i;
	int			index;
	int			size;

	i = -1;
	index = 0;
	size = 0;
	while (++i <= dna->rooms_nb)
	{
		if ((size = dna->rooms[dna->keyrooms[0]].index) != -1 && size * 2 < index)
			break ;
		if (dna->rooms[i].index == index)
		{
			if (!check_links(&dna->rooms[i].name, index, dna))
				error();
		}
		if (i == dna->rooms_nb)
		{
			i = -1;
			++index;
		}
	}
	bring_ants(dna);
}
