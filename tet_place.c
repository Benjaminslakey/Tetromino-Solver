/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 23:34:44 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/18 00:44:42 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		attempt_place(t_tet *tet, char **tet_map, int c, int r)
{
	int i;
	int cr;
	int **type;

	i = -1;
	cr = (c * 10) + r;
	type = tet->type;
	while (++i < 4)
	{
		if ((type[i][1] < 0) && (c + type[i][1] < 0))
			return (0);
		if (TYPE_PARSE(type[i]) != '.')
			return (0);
	}
	tet_place(tet, tet_map, cr, tet->letter);
	return (1);
}

void	tet_place(t_tet *node, char **tet_map, int cr, char w)
{
	int		c;
	int		r;
	int		hashes_placed;
	int		**ptr;

	c = cr / 10;
	r = cr % 10;
	hashes_placed = -1;
	ptr = node->type;
	while (++hashes_placed < 4)
		(TYPE_PARSE(ptr[hashes_placed])) = w;
}
