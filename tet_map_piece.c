/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:35:43 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/11 20:40:41 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char	*new_row(char *big, int *index, int delim)
{
	int		j;
	char	*new;

	j = 0;
	new = (char*)malloc(sizeof(char) * (d_strlen(big, *index, delim) + 2));
	MEM_GUARD(new);
	while (big[*index] && big[*index] != delim)
	{
		new[j] = big[*index];
		(*index)++;
		j++;
	}
	new[j] = '\n';
	new[++j] = 0;
	return (new);
}

char		**tet_map_piece(char const *s, char c)
{
	int		i;
	int		nth_row;
	char	**rows;

	i = 0;
	nth_row = 0;
	MEM_GUARD((char**)s);
	rows = (char**)malloc(sizeof(char*) * (w_dcount((char*)s, c) + 1));
	MEM_GUARD(rows);
	while (s[i])
	{
		if (s[i] != c)
		{
			rows[nth_row] = new_row((char*)s, &i, c);
			nth_row++;
		}
		else
			i++;
	}
	rows[nth_row] = 0;
	free((void*)s);
	return (rows);
}
