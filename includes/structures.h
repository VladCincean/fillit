#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_tetrimino
{
	char	t[4][4];
	char	letter;
}				t_tetrimino;

typedef struct	s_vector
{
	t_tetrimino	*array;
	int			size;
	int			capacity;
}				t_vector;

typedef struct	s_solution
{
	char	**matrix;
	int		n;
}				t_solution;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

#endif
