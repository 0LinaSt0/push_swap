/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_five_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:02 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:02 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting stack with three elems */
void	stack_on_free_elems(t_ps *st_a, int argc)
{
	int	least;

	least = the_least_elem (st_a, argc);
	if (least == 0)
	{
		if (st_a[least + 1].val_elem > st_a[least + 2].val_elem)
		{
			swap (st_a, argc);
			rotate (st_a, argc, 'a');
		}
	}
	else if (least == 1)
	{
		if (st_a[least - 1].val_elem > st_a[least + 1].val_elem)
			rotate (st_a, argc, 'a');
		else
			swap (st_a, argc);
	}
	else if (least == 2)
	{
		if (st_a[least - 2].val_elem > st_a[least - 1].val_elem)
			swap (st_a, argc);
		reverse_rotate (st_a, argc, 'a');
	}
}

/* function for movementing one or two least elems
	prepare stack for working with three elems */
void	four_N_five(t_ps *st_a, t_ps *st_b, int argc)
{
	int	i;
	int	least;

	least = 0;
	i = 0;
	while (i <= (argc - 2))
	{
		if (st_a[i].val_elem < st_a[least].val_elem)
			least = i;
		i++;
	}
	while (least <= ((argc - 1) / 2) && least)
	{
		rotate (st_a, argc, 'a');
		least--;
	}
	while (least > ((argc - 1)) / 2 && (least != (argc - 1)))
	{
		reverse_rotate (st_a, argc, 'a');
		least++;
	}
	push (st_a, st_b, argc, 'b');
}

/* function for workin with small stacks (2 - 5 elems) */
void	small_stacks(t_ps *st_a, t_ps *st_b, int argc)
{
	if ((argc - 1) == 2)
	{
		if (st_a[0].val_elem > st_a[1].val_elem)
			rotate (st_a, argc, 'a');
	}
	else if ((argc - 1) == 3)
		stack_on_free_elems (st_a, argc);
	else if ((argc - 1) == 4)
	{
		four_N_five (st_a, st_b, argc);
		stack_on_free_elems (st_a + 1, argc - 1);
		push (st_b, st_a, argc, 'a');
	}
	else if ((argc - 1) == 5)
	{
		four_N_five (st_a, st_b, argc);
		four_N_five (st_a + 1, st_b, argc - 1);
		stack_on_free_elems (st_a + 2, argc - 2);
		push (st_b, st_a, argc, 'a');
		push (st_b, st_a, argc, 'a');
	}
}
