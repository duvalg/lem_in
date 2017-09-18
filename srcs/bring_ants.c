/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:48:52 by gduval            #+#    #+#             */
/*   Updated: 2017/09/13 15:48:53 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void     init_ants_array(t_dna *dna)
{
    short int   i;

    i = -1;
    while (++i < dna->ants)
    {
        dna->ants_array[i].name = i + 1;
        dna->ants_array[i].room = &dna->rooms[dna->keyrooms[0]].name;
    }
}

static void     display_move(t_ants *ant)
{
    write(1, "L", 1);
    ft_putnbr(ant->name);
    write(1, "-", 1);
    ft_putstr(*ant->room);
    write(1, " ", 1);
}

static int      check_room(t_room *room, t_ants *ant, t_dna *dna, int index)
{
    if (room->index == index && index != -1)
        if ((room->active == 0 || !ft_strcmp(room->name, dna->rooms[dna->keyrooms[1]].name)))
        {
            if (!ft_strcmp(room->name, dna->rooms[dna->keyrooms[0]].name))
                return (0);
            if (ft_strcmp(*ant->room, dna->rooms[dna->keyrooms[0]].name))
                find_room_by_name(ant->room, dna)->active = 0;
            ant->room = &room->name;
            room->active = 1;
            display_move(ant);
            return (1);
        }
    return (0);
}

static int      check_links(t_ants *ants, t_dna *dna)
{
    t_links     *tmp;
    short int   add;
    int         index;

    add = -2;
    index = find_room_by_name(ants->room, dna)->index;
    while (++add <= 0)
    {
        tmp = dna->links;
        while (tmp->next)
        {
            if (!ft_strcmp(*ants->room, tmp->link_a))
            {
                if (check_room(find_room_by_name(&tmp->link_b, dna), ants, dna, index + add))
                    return (1);
            }
            else if (!ft_strcmp(*ants->room, tmp->link_b))
            {
                if (check_room(find_room_by_name(&tmp->link_a, dna), ants, dna, index + add))
                    return (1);
            }
            tmp = tmp->next;
        }
    }
    return (0);
}

static int      check_all_ants(t_dna *dna)
{
    int         i;

    i = -1;
    while (++i < dna->ants)
    {
        if (ft_strcmp(*dna->ants_array[i].room, \
            dna->rooms[dna->keyrooms[1]].name))
            return (0);
    }
    return (1);
}

void            bring_ants(t_dna *dna)
{
    t_ants      ants_array[dna->ants];
    short int   i;

    i = -1;
    dna->ants_array = (t_ants *)ants_array;
    init_ants_array(dna);
    while (++i < dna->ants)
    {
        if (check_all_ants(dna))
            break ;
        check_links(&dna->ants_array[i], dna);
        if (i == dna->ants - 1)
        {
            i = -1;
            write(1, "\n", 1);
        }
    }
    ft_exit(dna);
}
