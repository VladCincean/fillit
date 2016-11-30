#include "fillit.h"
#include <stdlib.h>

t_solution	*solution_init(int n)
{
	t_solution	*sol;
	int			i;

	sol = (t_solution*)malloc(sizeof(t_solution));
	sol->n = n;
	sol->matrix = (char**)malloc(sizeof(char*) * n);
	i = -1;
	while (++i < n)
	{
		sol->matrix[i] = (char*)malloc(sizeof(char) * (n + 1));
		ft_memset(sol->matrix[i], '.', n);
		sol->matrix[i][n] = '\0';
	}
	return (sol);
}

void		solution_destroy(t_solution *sol)
{
	int	i;

	i = 0;
	while (i < sol->n)
		free(sol->matrix[i++]);
	free(sol->matrix);
}

t_vector	*vector_init(int capacity)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (!v)
		return (NULL);
	v->array = (t_tetrimino *)malloc(sizeof(t_tetrimino) * capacity);
	if (!v->array)
	{
		free(v);
		return (NULL);
	}
	v->size = 0;
	v->capacity = capacity;
	return (v);
}

void		vector_destroy(t_vector *v)
{
	free(v->array);
}

int			vector_push_back(t_vector *v, t_tetrimino t)
{
	if (v->size >= v->capacity)
		return (0);
	v->array[v->size] = t;
	v->size++;
	return (1);
}
