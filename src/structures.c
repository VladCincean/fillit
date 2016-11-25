#include "fillit.h"
#include <stdlib.h>

t_solution	*get_empty_solution(int n)
{
	t_solution	*sol;
	int			i;

	sol = (t_solution*)malloc(sizeof(t_solution));
	sol->n = n;
	sol->matrix = (char**)malloc(sizeof(char*) * n);
	i = 0;
	while (i < size)
	{
		sol->matrix[i++] = (char*)malloc(sizeof(char) * (n + 1));
		// TODO: + memset to '.' or '\0' [...] idk
	}
	return (sol);
}

void		destroy_solution(t_solution *sol)
{
	int	i;

	i = 0;
	while (i < sol->n)
		free(sol->matrix[i++]);
	free(sol->matrix);
}

void		destroy_tetr_vector(t_tetr_vector *v)
{
	free(v->array); // :))
}
