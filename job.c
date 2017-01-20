#include "fillit.h"

static t_bool	four(char **tetr, int i, int j)
{
	if ((j && tetr[i][j - 1] != '#') && tetr[i][j + 1] != '#' && (i < 3 &&
		tetr[i + 1][j] != '#') && (i && tetr[i - 1][j] != '#'))
		error(E_INVALID); //single #
	return (TRUE);
}

static void	verif(char **tetr)
{
	int i;
	int j;
	int tetris;

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
				error(E_INVALID); //wrong character
			if (tetr[i][4] != '\n')
				error(E_INVALID); //no end of line
			tetr[i][4] = 0;
			j++;
		}
		if (tetris != 4)
			error(E_INVALID); //we need 4 tetris
		i++;
	}
}

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

static void	read_file(int fd, t_vector *v)
{

}
