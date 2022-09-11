/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:51 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:51 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* counts the number of occupied elems in stack */
int	el_num(t_ps *stack, int argc)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i <= (argc - 2))
	{
		if (stack[i].empt_fl)
			counter++;
		i++;
	}
	return (counter);
}

/*	finds elem which has the least number of operations
	for moving from stack A in stack B*/
int	optimal_elem(t_ps *stack, int argc)
{
	int	iter_1;
	int	optimal_el_b;

	iter_1 = 0;
	optimal_el_b = 0;
	while (iter_1 <= (argc - 2) && optimal_el_b < (argc - 2))
	{
		if (!stack[iter_1].empt_fl)
		{
			optimal_el_b = iter_1 + 1;
			iter_1++;
		}
		else
		{
			if (stack[optimal_el_b].iter_sum > stack[iter_1].iter_sum)
				optimal_el_b = iter_1;
			iter_1++;
		}
	}
	return (optimal_el_b);
}

/* finds the greatest elem in stack */
int	the_greatest_elem(t_ps *stack, int argc)
{
	int	first;
	int	iter_1;

	first = 0;
	iter_1 = 0;
	while (iter_1 <= (argc - 2))
	{
		if (stack[first].val_elem < stack[iter_1].val_elem)
			first = iter_1;
		iter_1++;
	}
	return (first);
}

/* finds the least elem in stack */
int	the_least_elem(t_ps *stack, int argc)
{
	int	last;
	int	iter_1;

	last = 0;
	iter_1 = 0;
	while (iter_1 <= (argc - 2))
	{
		if (!(iter_1 <= (argc - 2))
			|| stack[last].val_elem > stack[iter_1].val_elem)
			last = iter_1;
		iter_1++;
	}
	return (last);
}
