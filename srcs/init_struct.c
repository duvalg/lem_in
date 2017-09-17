/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:42:05 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 11:42:06 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_dna			init_dna(void)
{
	t_dna		dna;

	dna.ants = 0;
	dna.rooms_nb = 0;
	dna.keyrooms[0] = -1;
	dna.keyrooms[1] = -1;
	dna.room_lst = NULL;
	dna.rooms = NULL;
	return (dna);
}

t_links			*init_link(void)
{
	t_links		*link;

	if (!(link = ft_memalloc(sizeof(t_links))))
		return (NULL);
	link->link_a = NULL;
	link->link_b = NULL;
	link->next = NULL;
	return (link);
}
