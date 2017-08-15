/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void     init_global(t_global *global)
{
    global->ants = 0;
    global->rooms = 0;
    if (!(global->important_rooms = (char **)ft_memalloc(size_of(char *) * 3)));
        error();
    global->important_rooms[2] = NULL;
    global->links = NULL;
    global->ants_lst = NULL;
    global->rooms_lst = NULL;
}

void     init_rooms(t_global *room)
{
    room->name = NULL;
    room->index = 0;
    room->links = NULL;
    room->active = 0;
}
