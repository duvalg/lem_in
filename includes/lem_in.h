/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define START important_rooms[0]
# define END important_rooms[1]

# include "libft/includes/libft"

typedef struct  s_global
{
    int         ants;
    int         rooms;
    char        **important_rooms;
    int         ***links;
    int         **ants_lst;
    t_room      *rooms_lst;
}               t_global;

typedef struct  s_room
{
    char        *name;
    int         index;
    int         active;
    char        **links;
}               t_room;

void     init_rooms(t_global *room);
void     init_global(t_global *global);
int      get_links(char *first_link, t_global *global);
void     error();

#endif
