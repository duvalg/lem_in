/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:17:15 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 12:17:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	check_line(char **line)
{
	if (!ft_strlen(*line))
		error();
	else if (ft_strlen(*line) == 7)
	{
		if (!ft_strcmp(*line, "##start"))
			error();
	}
	else if (*line[0] != '#')
		error();
	else if (ft_strlen(*line) == 5)
	{
		if (!ft_strcmp(*line, "##end"))
			error();
	}
}

static int	get_ants(t_dna *dna, char **line)
{
	short int	ants;
	short int	ret;

	ants = 0;
	ret = 0;
	while ((ret = (unsigned short)get_next_line(0, line)) > 0)
	{
		if ((ants = (unsigned short)ft_atoi(*line)) != 0)
			break ;
		check_line(line);
		ft_putendl(*line);
	}
	if (ret < 0 || ants <= 0 || (long long)ants > 10000)
	{
		if (*line)
			ft_strdel(line);
		error();
	}
	dna->ants = ft_atoi(*line);
	ft_putendl((const char *)*line);
	ft_strdel(line);
	return (0);
}

static void	insert_key_room(int index, int *keyroom, t_dna *dna)
{
	switch (*keyroom)
	{
		case 1:
			if (dna->keyrooms[0] == -1)
				dna->keyrooms[0] = index;
			else
				error();
			break ;
		case 2:
			if (dna->keyrooms[1] == -1)
				dna->keyrooms[1] = index;
			else
				error();
			break ;
	}
	*keyroom = 0;
}

static char	**get_rooms(t_dna *dna, char **line)
{
	int			keyroom;
	char		*name;
	static char	*lst = NULL;

	name = NULL;
	keyroom = 0;
	while (get_next_line(0, line))
	{
		if (!ft_strlen(*line))
			error();
		if (*line[0] != '#' && !ft_strchr(*line, ' '))
			break ;
		else if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			keyroom = (!ft_strcmp("##end", *line)) ? 2 : 1;
		else
		{
			if (*line[0] != '#')
			{
				if (!(name = ft_strsub(*line, 0, (size_t)ft_strchri(*line, ' ') + 1)))
					error();
				else if (name[0] == 'L')
					error();
				else if (!(lst = (!lst) ? name : ft_strjoin_free(lst, name, 3)))
					error();
				insert_key_room(dna->rooms_nb, &keyroom, dna);
				++(dna->rooms_nb);
			}
		}
		ft_putendl((const char *)*line);
		ft_strdel(line);
	}
	return ((char **)&lst);
}

void		parse(t_dna *dna)
{
	char	*line;
	char	**room_lst;

	line = NULL;
	room_lst = NULL;
	get_ants(dna, &line);
	room_lst = get_rooms(dna, &line);
	if (dna->keyrooms[0] < 0 || dna->keyrooms[1] < 0)
		error();
	if (dna->keyrooms[0] == dna->keyrooms[1])
		error();
	if (!(dna->room_lst = ft_strsplit(*room_lst, ' ')))
		error();
	ft_strdel(room_lst);
	create_rooms(&line, dna);
}
