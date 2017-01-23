#include "fillit.h"

static int	four(char tetr[5][5], int i, int j)
{
	if ((j && tetr[i][j - 1] != '#') && tetr[i][j + 1] != '#' && (i < 3 &&
		tetr[i + 1][j] != '#') && (i && tetr[i - 1][j] != '#'))
		return (0); //single #
	return (1);
}

static int	verif(char tetr[5][5])
{
	int	i;
	int	j;
	int	tetris;

	tetris = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#' && four(tetr, i, j))
				tetris++;
			else if (tetr[i][j] != '.')
				return (0); //wrong character
			if (tetr[i][4] != '\n')
				return (0); //no end of line
			tetr[i][4] = 0;
			j++;
		}
		if (tetris != 4)
			return (0); //we need 4 tetris
		i++;
	}
	return (1);
}

/*
static char	**new(void)
{
	char	**tetr;
	int	i;

	if (!(tetr = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
		tetr[i++] = (char *)malloc(sizeof(char) * 5);
	tetr[i] = NULL;
	return (tetr);
}
*/

int			validate_tetris(t_tetrimino *t)
{
	return (verif(t->t));
}
