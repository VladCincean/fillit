/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:54:23 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/14 12:00:19 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define CHAR_NULL '\0'
# define CHAR_DOT '.'
# define CHAR_HASH '#'
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
**	Defined in reader.c
*/

//...

/*
**	Defined in solver.c
*/

t_solution	*solve(t_vector *v);

/*
**	Defined in solver_utils.c
*/

int			get_height(t_tetrimino t);
int			get_width(t_tetrimino t);
int			has_conflicts(t_solution *sol, t_tetrimino t, int x, int y);
void		put_tetrimino(t_solution *sol, t_tetrimino t, int x, int y);
void		del_tetrimino(t_solution *sol, t_tetrimino t, int x, int y);

/*
**	Defined in printer.c
*/

//...

/*
**	Defined in string_functions.h
*/

void		*ft_memset(void *s, int c, unsigned int n);
void		ft_putstr(char *s);
int			ft_strlen(char *s);

/*
**	Defined in main.c
*/

void		f_error(void);
void		f_usage(char *argv0);

#endif
