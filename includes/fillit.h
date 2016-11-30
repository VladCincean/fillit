#ifndef FILLIT_H
# define FILLIT_H
# include "structures.h"

/*
**	Defined in structures.c
 */

t_solution	*solution_init(int n);
void		solution_destroy(t_solution *sol);
t_vector	*vector_init(int capacity);
void		vector_destroy(t_vector *v);
int			vector_push_back(t_vector *v, t_tetrimino t);

/*
**	Defined in ...
 */

// ...

/*
**	Defined in main.c
 */

void 		ft_error();

#endif
