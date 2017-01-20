/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:55:00 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/14 11:55:04 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#endif
