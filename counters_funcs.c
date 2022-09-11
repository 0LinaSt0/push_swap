/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:14 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:15 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	counts the number of needing operations (rotate or reverse) for puting
	every elems of stack B in his plase of stack A */
void	place_operation_counter(t_ps *st_a, t_ps *st_b, int argc, int i_b)
{
	int	half;
	int	a_;

	half = el_num(st_a, argc) / 2;
	a_ = (argc - 1) - el_num(st_a, argc);
	while (a_ <= (argc - 2))
	{
		if (st_b[i_b].val_elem > st_a[a_].val_elem
			&& st_b[i_b].val_elem < st_a[a_ + 1].val_elem
			&& st_a[a_].empt_fl && st_a[a_ + 1].empt_fl)
		{
			if (el_num(st_a, argc) - ((argc - 1) - a_) <= half)
			{
				st_b[i_b].pl_count_rotate = el_num(st_a, argc) - argc + 2 + a_;
				st_b[i_b].fl_pl_rotate = 1;
			}
			else if (el_num(st_a, argc) - ((argc - 1) - a_) > half)
			{
				st_b[i_b].pl_count_reverse = el_num(st_a, argc)
					- (el_num(st_a, argc) - ((argc - 2) - a_));
				st_b[i_b].fl_pl_reverse = 1;
			}
		}
		a_++;
	}
}

void	up_operation_counter_1(t_ps *stack, int argc, int num_el)
{
	int	iter;

	iter = num_el + 1;
	while (iter <= (argc - 2))
	{
		if (stack[iter++].empt_fl)
		{
			stack[num_el].up_count_reverse++;
			stack[num_el].fl_up_reverse = 1;
		}
	}
	stack[num_el].up_count_reverse++;
	stack[num_el].fl_up_reverse = 1;
}

/*	counts the number of needing operations for puting some stack's
	element at the top */
void	up_operation_counter(t_ps *stack, int argc, int num_el)
{
	int	iter;
	int	start;

	start = (argc - 1) - el_num(stack, argc);
	iter = 0;
	if (num_el - start <= el_num(stack, argc) / 2)
	{
		while (iter != num_el && stack[num_el].up_count_rotate < num_el - 2
			&& iter <= (argc - 2))
		{
			if (stack[iter++].empt_fl)
			{
				stack[num_el].up_count_rotate++;
				stack[num_el].fl_up_rotate = 1;
			}
		}
	}
	else
		up_operation_counter_1(stack, argc, num_el);
}
