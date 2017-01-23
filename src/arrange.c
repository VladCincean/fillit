#include "fillit.h"

static void	up(char tetr[5][5])
{
	char	tmp;
	int		i;

	i = 0;
	while (i++ < 4)
	{
		tmp = tetr[0][i];
		tetr[0][i] = tetr[1][i];
		tetr[1][i] = tetr[2][i];
		tetr[2][i] = tetr[3][i];
		tetr[3][i] = tmp;
	}
}

static void	left(char tetr[5][5])
{
	char	tmp;
	int		i;

	i = 0;
	while (i++ < 4)
	{
		tmp = tetr[i][0];
		tetr[i][0] = tetr[i][1];
		tetr[i][1] = tetr[i][2];
		tetr[i][2] = tetr[i][3];
		tetr[i][3] = tmp;
	}
}

static void	up_left(char tetr[5][5])
{
	while (tetr[0][0] == '.' && tetr[1][0] == '.' && tetr[2][0] == '.' &&
		tetr[3][0] == '.')
		left(tetr);
	while (tetr[0][0] == '.' && tetr[0][1] == '.' && tetr[0][2] == '.' &&
		tetr[0][3] == '.')
		up(tetr);
}

void		arrange_tetris(t_tetrimino *t)
{
	up_left(t->t);
}
