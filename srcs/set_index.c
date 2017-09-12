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
#include <stdio.h> //adw

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
	return (0);
}

void				check_room(t_room *room, short int index)
{
	if (room->index == -1)
	{
		if (room)
			room->index = index + 1;
	}
}

int					links_broken(short int index, t_dna *dna)
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
	int				set_one;
	t_links			*tmp;

	set_one = 0;
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

// DEBUG
static int			display_rooms(t_dna *dna)
{
	int i = -1;

	printf("\n\nstart room -> %s\n", dna->rooms[dna->keyrooms[0]].name);
	printf("end room -> %s\n", dna->rooms[dna->keyrooms[1]].name);
	printf("number of rooms -> %d\n\n", dna->rooms_nb);
	while (++i < dna->rooms_nb)
	{
		printf("name -> %s\n", dna->rooms[i].name);
		printf("index -> %d\n", dna->rooms[i].index);
		printf("active -> %d\n\n", dna->rooms[i].active);
	}
	return (0);
}
// END

void				set_index(t_dna *dna)
{
	short int		i;
	short int		index;

	i = -1;
	index = 0;
	while (++i < dna->rooms_nb && index >= 0)
	{
		if (index >= 1)
			if (links_broken(index, dna))
				break;
		if (dna->rooms[dna->keyrooms[0]].index != -1)
			break;
		if ((unsigned short)dna->rooms[i].index == index)
		{
			if (!check_links(&dna->rooms[i].name, index, dna))
				exit (0);
		}
		if (i == dna->rooms_nb - 1)
		{
			i = -1;
			++index;
		}
	}
	display_rooms(dna);
	ft_exit(dna);
}
