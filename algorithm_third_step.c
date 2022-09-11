/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_third_step.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:57:32 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:57:32 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* for combination (B)re -- (A)re */
void	Bre_Are(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b)
{
	while (st_b[optimal_el_b].up_count_reverse
		&& st_b[optimal_el_b].pl_count_reverse)
	{
		reverse_rotate_a_b (st_a, st_b, argc, '-');
		st_b[optimal_el_b].up_count_reverse--;
		st_b[optimal_el_b].pl_count_reverse--;
	}
	while (st_b[optimal_el_b].up_count_reverse)
	{
		reverse_rotate (st_b, argc, 'b');
		st_b[optimal_el_b].up_count_reverse--;
	}
	while (st_b[optimal_el_b].pl_count_reverse)
	{
		reverse_rotate (st_a, argc, 'a');
		st_b[optimal_el_b].pl_count_reverse--;
	}
	push (st_b, st_a, argc, 'a');
}

/* for combination (B)ro -- (A)ro */
void	Bro_Aro(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b)
{
	while (st_b[optimal_el_b].up_count_rotate
		&& st_b[optimal_el_b].pl_count_rotate)
	{
		rotate_a_b (st_a, st_b, argc, '-');
		st_b[optimal_el_b].up_count_rotate--;
		st_b[optimal_el_b].pl_count_rotate--;
	}
	while (st_b[optimal_el_b].up_count_rotate)
	{
		rotate (st_b, argc, 'b');
		st_b[optimal_el_b].up_count_rotate--;
	}
	while (st_b[optimal_el_b].pl_count_rotate)
	{
		rotate (st_a, argc, 'a');
		st_b[optimal_el_b].pl_count_rotate--;
	}
	push (st_b, st_a, argc, 'a');
}

/* for combination (B)re -- (A)ro || (B)re -- (A) || (B) -- (A)ro */
void	BreAro_BreA_BAro(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b)
{
	while (st_b[optimal_el_b].up_count_reverse)
	{
		reverse_rotate (st_b, argc, 'b');
		st_b[optimal_el_b].up_count_reverse--;
	}
	while (st_b[optimal_el_b].pl_count_rotate)
	{
		rotate (st_a, argc, 'a');
		st_b[optimal_el_b].pl_count_rotate--;
	}
	push (st_b, st_a, argc, 'a');
}

/* for combination (B)ro -- (A)re || (B)ro -- (A) || (B) -- (A)re */
void	BroAre_BroA_BAre(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b)
{
	while (st_b[optimal_el_b].up_count_rotate)
	{
		rotate (st_b, argc, 'b');
		st_b[optimal_el_b].up_count_rotate--;
	}
	while (st_b[optimal_el_b].pl_count_reverse)
	{
		reverse_rotate (st_a, argc, 'a');
		st_b[optimal_el_b].pl_count_reverse--;
	}
	push (st_b, st_a, argc, 'a');
}

/*	movins elem with the least number of operations from stack B to stack A*/
void	algorithm_third_step(t_ps *st_a, t_ps *st_b, int argc)
{
	int	opt_el_b;

	opt_el_b = algorithm_second_step (st_a, st_b, argc);
	if (st_b[opt_el_b].fl_up_reverse && st_b[opt_el_b].fl_pl_reverse)
	{
		Bre_Are (st_a, st_b, argc, opt_el_b);
	}
	else if (st_b[opt_el_b].fl_up_rotate && st_b[opt_el_b].fl_pl_rotate)
	{
		Bro_Aro (st_a, st_b, argc, opt_el_b);
	}
	else if ((st_b[opt_el_b].fl_up_reverse && st_b[opt_el_b].fl_pl_rotate)
		|| st_b[opt_el_b].fl_up_reverse || st_b[opt_el_b].fl_pl_rotate)
	{
		BreAro_BreA_BAro (st_a, st_b, argc, opt_el_b);
	}
	else if ((st_b[opt_el_b].fl_up_rotate && st_b[opt_el_b].fl_pl_reverse)
		|| st_b[opt_el_b].fl_up_rotate || st_b[opt_el_b].fl_pl_reverse)
	{
		BroAre_BroA_BAre (st_a, st_b, argc, opt_el_b);
	}
	else
		push (st_b, st_a, argc, 'a');
}
