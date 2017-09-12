/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:48:52 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 15:48:53 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			create_rooms(char **line, t_dna *dna)
{
	int			i;
	t_room		rooms[dna->rooms_nb];

	i = -1;
	while (dna->room_lst[++i])
	{
		rooms[i].name = ft_strdup(dna->room_lst[i]);
		rooms[i].active = 0;
		if (i == dna->keyrooms[1])
			rooms[i].index = 0;
		else
			rooms[i].index = -1;
	}
	dna->rooms = (t_room *)rooms;
	get_links(line, dna);
}
