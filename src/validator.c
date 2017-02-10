/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeculea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:51:21 by apeculea          #+#    #+#             */
/*   Updated: 2017/02/05 13:51:17 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//TODO: cazul in care '#'-urile nu sunt unite toate
//TODO: cazul in care un '#' are un vecin '#' "pe diagonala"

static int	four(char tetr[5][5], int i, int j)
{
//	if ((j && tetr[i][j - 1] != '#') && tetr[i][j + 1] != '#' && (i < 3 &&
//		tetr[i + 1][j] != '#') && (i && tetr[i - 1][j] != '#'))
//		return (0); //single #
	int	count;

	count = 0;
	if (j > 0 && tetr[i][j - 1] == '#')
		count++;
	if (j < 3 && tetr[i][j + 1] == '#')
		count++;
	if (i > 0 && tetr[i - 1][j] == '#')
		count++;
	if (i < 3 && tetr[i + 1][j] == '#')
		count++;
	return (1 <= count && count <= 3);
}

static int	verif(char tetr[5][5])
{
	int	i;
	int	j;
	int	nr;

	nr = 0;
	i = -1;
	while (++i < 4)
	{
		if (tetr[i][4] != '\n')
			return (0);
		j = -1;
		while (++j < 4)
		{
			if (!(tetr[i][j] == '#' || tetr[i][j] == '.'))
				return (0);
			if (tetr[i][j] == '#' && four(tetr, i, j) != 0)
				nr++;
		}
	}
	return (nr == 4);
}

int			validate_tetris(t_tetrimino *t)
{
	return (verif(t->t));
}
