/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 05:11:49 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/21 00:23:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	char	**map_creator(int map_size)
{
	int		i;
	int		j;
	char	**ret_map;

	i = -1;
	j = 0;
	ret_map = (char**)malloc(sizeof(char*) * (map_size + 1));
	ret_map[map_size] = 0;
	while (++i < map_size)
	{
		ret_map[i] = ft_strnew(map_size);
		j = 0;
		while (j < map_size)
		{
			ret_map[i][j] = '.';
			j++;
		}
	}
	i = -1;
	return (ret_map);
}

static void		reset_map(char **grid)
{
	int i;

	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
}

static int		solve_grid(t_tet *tet, char **map, int map_size)
{
	int		c;
	int		r;
	int		cr;

	if (tet == NULL)
		return (1);
	r = 0;
	while (r < (map_size - tet->height) + 1)
	{
		c = 0;
		while (c < (map_size - tet->width) + 1)
		{
			if (attempt_place(tet, map, c, r))
			{
				if (solve_grid(tet->next, map, map_size))
					return (1);
				cr = (c * 10) + r;
				tet_place(tet, map, cr, '.');
			}
			c++;
		}
		r++;
	}
	return (0);
}

char			**tet_solver(t_tet **head, int list_length)
{
	int			map_size;
	char		**tet_solution;

	map_size = ft_sqrt((list_length * 4));
	if ((map_size * map_size) < (list_length * 4))
		map_size++;
	tet_solution = map_creator(map_size);
	while (!solve_grid(*head, tet_solution, map_size))
	{
		reset_map(tet_solution);
		tet_solution = map_creator(++map_size);
	}
	return (tet_solution);
}
