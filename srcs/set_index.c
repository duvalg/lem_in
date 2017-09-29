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

static void			check_room(t_room *room, short int *index)
{
	if (room->index == -1)
	{
		if (room)
			room->index = *index + 1;
	}
}

int					check_links(char **name, short int index, t_dna *dna)
{
	t_links			*tmp;
	t_room			*tmp_room;
	size_t			size;

	tmp = dna->links;
	size = ft_strlen(*name);
	while (tmp->next)
	{
		if (!ft_strcmp(*name, tmp->link_a) && size == ft_strlen(tmp->link_a))
		{
			if (!(tmp_room = find_room_by_name(&tmp->link_b, dna)))
				break ;
			check_room(tmp_room, &index);
		}
		if (!ft_strcmp(*name, tmp->link_b) && size == ft_strlen(tmp->link_b))
		{
			if (!(tmp_room = find_room_by_name(&tmp->link_a, dna)))
				break ;
			check_room(tmp_room, &index);
		}
		tmp = tmp->next;
	}
	return (1);
}

int					broken_links_verification(t_dna *dna, int index)
{
	int				i;

	i = -1;
	while (++i < dna->rooms_nb)
	{
		if (dna->rooms[i].index == index - 1)
			return (1);
	}
	return (0);
}

void				set_index(t_dna *dna)
{
	int			i;
	int			index;
	int			size;

	i = -1;
	index = 0;
	size = 0;
	while (++i < dna->rooms_nb)
	{
		if (!broken_links_verification(dna, index))
			break ;
		size = dna->rooms[dna->keyrooms[0]].index;
		if (size != -1 && size < index)
			break ;
		if (dna->rooms[i].index == index)
			check_links(&dna->rooms[i].name, index, dna);
		if (i == dna->rooms_nb - 1)
		{
			i = -1;
			++index;
		}
	}
	if (dna->rooms[START].index == -1 || dna->rooms[END].index == -1)
		error();
	bring_ants(dna);
}
