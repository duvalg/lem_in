/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:10:28 by gduval            #+#    #+#             */
/*   Updated: 2017/09/25 15:10:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		check_line(char **line)
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

int				get_ants(t_dna *dna, char **line)
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
