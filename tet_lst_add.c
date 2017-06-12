/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 04:54:53 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/17 23:41:34 by rmanese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		x_or_y_len(char axis, int **type)
{
	int	diff;
	int	i;

	i = 0;
	if (axis == 'y')
	{
		diff = type[i][0];
		while (++i < 4)
			if (diff < type[i][0])
				diff = type[i][0];
	}
	else
	{
		diff = type[i][1];
		while (++i < 4)
			if (diff < type[i][1])
				diff = type[i][1];
	}
	return (diff + 1);
}

static int		**type_parse(int *t)
{
	int	i;
	int **parsed;

	i = 0;
	parsed = (int**)malloc(sizeof(int*) * 4);
	while (i < 4)
	{
		parsed[i] = (int*)malloc(sizeof(int) * 2);
		parsed[i][0] = 0;
		parsed[i][1] = 0;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		parsed[i + 1][0] = (((t[i + 1] / 10) - (t[0] / 10)));
		parsed[i + 1][1] += ((t[i + 1] % 10) - (t[0] % 10));
		i++;
	}
	return (parsed);
}

static int		**type_finder(char **tet_grid)
{
	int *hash_coords;

	VAR3_INIT0(i, j, found);
	hash_coords = (int*)malloc(sizeof(int) * 4);
	while (tet_grid[i])
	{
		j = 0;
		while (tet_grid[i][j])
		{
			if (tet_grid[i][j] == '#')
			{
				hash_coords[found] = ((i * 10) + j);
				found++;
			}
			j++;
		}
		i++;
	}
	return (type_parse(hash_coords));
}

static t_tet	*tet_add_node(char **grid, char alpha)
{
	t_tet *new;

	new = (t_tet*)malloc(sizeof(t_tet));
	MEM_GUARD(new);
	new->type = type_finder(grid);
	new->height = x_or_y_len('y', new->type);
	new->width = x_or_y_len('x', new->type);
	new->letter = alpha;
	new->next = NULL;
	return (new);
}

t_tet			*tet_lst_map(char *tet_file, int num_tets)
{
	int		nth_node;
	char	*temp;
	char	**grid;
	t_tet	*lst_head;
	t_tet	*curr_node;

	nth_node = -1;
	while (++nth_node < num_tets)
	{
		temp = ft_strndup(tet_file, 21);
		grid = tet_map_piece(ft_strdup(temp), '\n');
		ERR_GUARD((tet_piece_chk(grid) == 0), NULL);
		if (nth_node == 0)
		{
			MEM_GUARD((curr_node = tet_add_node(grid, (65 + nth_node))));
			lst_head = curr_node;
		}
		else
		{
			MEM_GUARD((curr_node->next = tet_add_node(grid, (65 + nth_node))));
			curr_node = curr_node->next;
		}
		tet_file += 21;
	}
	return (lst_head);
}
