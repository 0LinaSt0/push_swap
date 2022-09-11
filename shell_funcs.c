/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:31 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* shell-functions for printing the name of operation */
void	push_shell(char fl)
{
	if (fl == 'a')
		write (1, "pa\n", 3);
	else if (fl == 'b')
		write (1, "pb\n", 3);
}

void	rotate_a_b(t_ps *st_a, t_ps *st_b, int argc, char fl)
{
	rotate (st_b, argc, fl);
	rotate (st_a, argc, fl);
	write (1, "rr\n", 3);
}

void	rotate_shell(char fl)
{
	if (fl == 'a')
		write (1, "ra\n", 3);
	else if (fl == 'b')
		write (1, "rb\n", 3);
}

void	reverse_rotate_a_b(t_ps *st_a, t_ps *st_b, int argc, char fl)
{
	reverse_rotate (st_b, argc, fl);
	reverse_rotate (st_a, argc, fl);
	write (1, "rrr\n", 4);
}

void	rev_rot_shell(char fl)
{
	if (fl == 'a')
		write (1, "rra\n", 4);
	else if (fl == 'b')
		write (1, "rrb\n", 4);
}
