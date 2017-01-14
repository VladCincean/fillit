/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:55:11 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/14 11:58:23 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	f_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	f_usage(char *argv0)
{
	ft_putstr("usage: "); // TODO: ...
	ft_putstr(argv0);
	ft_putstr(" input_file\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_vector	*v;
	t_solution	*sol;

	if (argc != 2)
		f_usage(argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		f_error();
	v = vector_init(27); // 26 litere + 1
	read_file(fd, v); // sau ceva de genul...
	close(fd);
	sol = solve(v);
	print_solution(sol); // sau ceva de genul...
	vector_destroy(v);
	solution_destroy(sol);
	return (0);
}
