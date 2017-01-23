/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:56:13 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/23 15:17:54 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	do_solve(t_solution *sol, t_tetrimino *v)
{
	int	height;
	int	width;
	int	x;
	int	y;

	if (v[0].letter == CHAR_NULL)
		return (1);
	height = get_height(v[0]);
	width = get_width(v[0]);
	x = -1;
	while (++x < sol->n - width)
	{
		y = -1;
		while (++y < sol->n - height)
		{
			if (!has_conflicts(sol, v[0], x, y))
			{
				put_tetrimino(sol, v[0], x, y);
				if (do_solve(sol, &v[1]) == 1)
					return (1);
				del_tetrimino(sol, v[0], x, y);
			}
		}
	}
	return (0);
}

static int	floor_sqrt(int n)
{
	int sqrt;

	sqrt = 1;
	while (sqrt * sqrt <= n)
	{
		if (sqrt * sqrt == n)
			return (sqrt);
		if (sqrt * sqrt > n)
			return (sqrt - 1);
		sqrt++;
	}
	return (1);
}

t_solution	*solve(t_vector *v)
{
	t_solution	*sol;
	int			size;

	size = floor_sqrt(v->size);
	sol = NULL;
	while (1)
	{
		sol = solution_init(size);
		if (sol == NULL || do_solve(sol, v->array) == 0)
			break ;
		solution_destroy(sol);
		size++;
	}
	return (sol);
}
