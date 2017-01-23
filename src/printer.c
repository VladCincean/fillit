/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:02:41 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/23 15:06:38 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(t_solution *sol)
{
	int	i;

	i = 0;
	while (i < sol->n)
	{
		ft_putstr_fd(sol->matrix[i], 1);
		i++;
	}
}
