#include "fillit.h"

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

t_solution*	solve(t_vector *v)
{
	t_solution	*sol;
	int			size;

	size = 2; // TODO: use a known lower-bound
	sol = 0;  // i.e. sol = NULL;
	while (1)
	{
		sol = solution_init(size);
		if (do_solve(sol, v->array))
			break ;
		solution_destroy(sol);
		size++;
	}
	return (sol);
}
