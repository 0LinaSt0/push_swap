/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:45 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:45 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*a) puts all elems of stack A in stack B exept least and greatest
  b) swap the least and greatest elements of stack A ascending */
void	algorithm_first_step(t_ps *st_a, t_ps *st_b, int argc)
{
	int	iter_1;
	int	first;
	int	last;

	iter_1 = 0;
	first = the_greatest_elem (st_a, argc);
	last = the_least_elem (st_a, argc);
	while (iter_1 <= (argc - 2))
	{
		if (st_a[iter_1].val_elem == st_a[first].val_elem
			|| st_a[iter_1].val_elem == st_a[last].val_elem)
			rotate (st_a, argc, 'a');
		else
			push (st_a, st_b, argc, 'b');
		iter_1++;
	}
	if (st_a[argc - 3].val_elem > st_a[argc - 2].val_elem)
		swap(st_a, argc);
}

/*	counts the sum number of all operation every elements for moving it in
	stack A and returns the elem with the mosst optimal number of operations*/
int	algorithm_second_step(t_ps *st_a, t_ps *st_b, int argc)
{
	int	iter_1;
	int	optimal_el_b;

	iter_1 = 0;
	optimal_el_b = 0;
	while (iter_1 <= (argc - 2))
	{
		if (st_b[iter_1].empt_fl)
		{
			up_operation_counter (st_b, argc, iter_1);
			place_operation_counter (st_a, st_b, argc, iter_1);
			st_b[iter_1].iter_sum = st_b[iter_1].up_count_reverse
				+ st_b[iter_1].up_count_rotate + st_b[iter_1].pl_count_reverse
				+ st_b[iter_1].pl_count_rotate;
		}
		iter_1++;
	}
	optimal_el_b = optimal_elem (st_b, argc);
	return (optimal_el_b);
}

/*	final rotate or reverse of stack A for sorting from less to more */
void	algorithm_fourth_step(t_ps *st_a, int argc)
{
	int	min;
	int	rot;
	int	rev;

	min = the_least_elem (st_a, argc);
	rot = 0;
	rev = 0;
	if (min != 0)
	{
		if (min <= (argc - 1) / 2)
		{
			rot = min;
			while (rot)
			{
				rotate (st_a, argc, 'a');
				rot--;
			}
		}
		else if (min > (argc - 1) / 2)
		{
			rev = (argc - 1) - min;
			while (rev--)
				reverse_rotate (st_a, argc, 'a');
		}
	}
}
