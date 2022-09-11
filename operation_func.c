/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:26 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:27 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps *stack, int argc)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	while (stack[i].empt_fl == 0 && i <= (argc - 2))
		i++;
	temp = (stack[i]).val_elem;
	(stack[i]).val_elem = (stack[i + 1]).val_elem;
	(stack[i + 1]).val_elem = temp;
	write (1, "sa\n", 3);
}

void	push(t_ps *st_1, t_ps *st_2, int argc, char fl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= (argc - 2))
	{
		if (st_1[i].empt_fl == 0)
			i++;
		else
		{
			while (st_2[j].empt_fl == 0 && j <= (argc - 2))
				j++;
			j--;
			st_2[j].val_elem = st_1[i].val_elem;
			st_1[i].val_elem = 0;
			st_1[i].empt_fl = 0;
			st_2[j].empt_fl = 1;
			i = argc - 1;
		}
	}
	push_shell (fl);
}

void	rotate(t_ps *stack, int argc, char fl_a)
{
	int	i;
	int	temp;

	i = 0;
	while (stack[i].empt_fl == 0 && i <= (argc - 2))
		i++;
	temp = stack[i].val_elem;
	while (i < (argc - 2))
	{
		stack[i].val_elem = stack[i + 1].val_elem;
		i++;
	}
	stack[i].val_elem = temp;
	rotate_shell (fl_a);
}

void	reverse_rotate(t_ps *stack, int argc, char fl)
{
	int	i;
	int	temp;

	i = argc - 2;
	temp = stack[i].val_elem;
	while (i > 0)
	{
		stack[i].val_elem = stack[i - 1].val_elem;
		i--;
	}
	while (stack[i].empt_fl == 0 && i <= (argc - 2))
		i++;
	stack[i].val_elem = temp;
	rev_rot_shell (fl);
}
