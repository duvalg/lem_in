/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void     set_index_all(t_global **global)
{

}

static void     set_end_index(t_global **global)
{
    t_room      *tmp_room;

    tmp_room = *(global)->room;
    while (ft_strcmp(tmp_room->name, global->END))
        tmp_room++;
    tmp_room->index = 0;
}

void            get_index(t_global *global)
{
    set_end_index(&global);
    set_index_all(&global);
}
