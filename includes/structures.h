#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_tetrimino
{
	char	t[4][4];
	char	letter;
}				t_tetrimino;

typedef struct	s_tetr_vector
{
	t_tetrimino	*array;
	int			size;
}				t_tetr_vector;

typedef struct	s_solution
{
	char	**matrix;
	int		n;
}				t_solution;

#endif