/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:52:04 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/05 13:31:13 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

void	read_file(int fd, t_vector *v)
{
	t_tetrimino	t;
	int			size_read;
	char		letter;

	letter = 'A';
	while ((size_read = read(fd, t.t, 21)) >= 20)
	{
		arrange_tetris(&t);
		//TODO: make validator work
		if (validate_tetris(&t) == 0)
		{
			vector_destroy(v);
			f_error();
		}
		t.letter = letter++;
		vector_push_back(v, t);
	}
	if (size_read != 0)
	{
		vector_destroy(v);
		f_error();
	}
	t.letter = CHAR_NULL;
	vector_push_back(v, t);
}
