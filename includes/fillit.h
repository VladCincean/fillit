#ifndef FILLIT_H
# define FILLIT_H
# include "structures.h"

/*
**	Defined in structures.c
 */

t_solution	*get_empty_solution(int n);
void		destroy_solution(t_solution *sol);
void		destroy_tetr_vector(t_tetr_vector *v);

/*
**	Defined in ...
 */

// ...

/*
**	DEfined in main.c
 */

void 		ft_error();

#endif
