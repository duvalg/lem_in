/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/len_in.h"

static void  get_ants(t_global *global)
{
    char    *line;

    line = NULL;
    if (get_next_line(0, &line) <= 0)
    {
        if (line)
            ft_strdel(&line);
        error();
    }
    if ((global->ants = ft_atoi(line)) <= 0)
    {
        if (line)
            ft_strdel(&line);
        error();
    }
    if (ft_strlen(line) != ft_intlen(global->ants))
    {
        ft_strdel(&line);
        error();
    }
    ft_strdel(&line);
}

static int  check_line(char *line, int important room, t_global *global)
{
    if (!ft_strcmp(line, "##start") && ft_strlen(line) == 7)
        return (1);
    else if (!ft_strcmp(line, "##end") && ft_strlen(line) == 5)
        return (2);
    return (0);
}

static int  insert_room(char *line, char **lst_name, \
    int important_room, t_global *global)
{
    char        *tmp;
    int         i;

    tmp = NULL;
    i = 0;
    while (line[i] && line[i] != ' ')
        i++;
    i += 1;
    tmp = ft_strsub(line, 0, i);
    if (*lst_name)
        *lst_name = ft_strjoin_clean(*lst_name, tmp, 1)
    else
        *lst_name = ft_strdup(tmp);
    if (important_room == 1)
        global->START = ft_strdup(tmp);
    else if (important_room == 2)
        global->END = ft_strdup(tmp);
    ft_strdel(&tmp);
    global->rooms++;
}

static void  init_room(char **name, t_room *room)
{
    room->name = ft_strdup(*name);
    room->index = 0;
    room->active = 0;
    room->links = NULL;
    ft_strdel(name);
}

static char *get_rooms(char **basic_lst_names, t_global *global)
{
    int     important_room;
    char    *line;
    char    *lst_name;
    int     i;

    i  = -1;
    line = NULL;
    lst_name = NULL;
    while (get_next_line(0, &line) > 0)
    {
        if (!ft_strchr(line, ' '))
            break;
        important_room = check_line(line, important_room, global));
        insert_room(line, important_room, global);
        ft_strdel(&line);
    }
    *basic_lst_names = ft_strsplit(lst_name, ' ');
    if (!(global->rooms_lst = (t_room *)ft_memalloc(sizeof(t_room) * \
    (global->rooms + 1))))
        error();
    global->rooms_lst[global->room] = NULL;
    while (++i < global->rooms)
        init_room(&(basic_lst_names[i]), &global->rooms_lst);
    ft_memdel((void **)&basic_lst_names);
    return (line);
}

void         parse(t_global *global)
{
    char    *first_link;
    char    **basic_lst_names;

    first_link = NULL;
    basic_lst_names = NULL;
    get_ants(global); // DONE
    first_link = get_rooms(&basic_lst_names, global);
    get_links(first_link, global);
}
