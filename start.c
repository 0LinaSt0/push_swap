/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:41 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:42 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start(t_ps *st_a, t_ps *st_b, int argc)
{
	int	iter_stack;

	iter_stack = (argc - 3);
	if ((argc - 1) <= 5)
		small_stacks (st_a, st_b, argc);
	else
	{
		algorithm_first_step (st_a, st_b, argc);
		while (iter_stack)
		{
			algorithm_third_step (st_a, st_b, argc);
			initialization_of_struct (st_b, argc, 0);
			iter_stack--;
		}
	}
	algorithm_fourth_step (st_a, argc);
}

/* frees or/and exits out of program if something wrong */
void	ft_free_Nor_exit(t_ps *st_a, t_ps *st_b, int fl)
{
	if (fl == 'a' || fl == 'b' || fl == 'N')
	{
		if (fl == 'a')
			free (st_b);
		else if (fl == 'b')
			free (st_a);
		ft_putendl_fd("Error", 1);
		exit (1);
	}
	else if (fl == 1 || fl == 2 || fl == 3)
	{
		free (st_a);
		free (st_b);
		if (fl == 1 || fl == 3)
		{
			if (fl == 1)
				ft_putendl_fd("Error", 1);
			exit (1);
		}
	}
}

void	initialization_of_struct(t_ps *stack, int argc, int fl)
{
	int	i;

	i = 0;
	while (i <= argc - 2)
	{
		if (fl)
		{
			stack[i].empt_fl = 0;
			stack[i].val_elem = 0;
		}
		stack[i].up_count_rotate = 0;
		stack[i].up_count_reverse = 0;
		stack[i].pl_count_rotate = 0;
		stack[i].pl_count_reverse = 0;
		stack[i].fl_up_rotate = 0;
		stack[i].fl_up_reverse = 0;
		stack[i].fl_pl_rotate = 0;
		stack[i].fl_pl_reverse = 0;
		stack[i].iter_sum = 0;
		i++;
	}
}

void	initialization_of_stacks(int argc, char **argv)
{
	int		i;
	t_ps	*st_a;
	t_ps	*st_b;

	st_a = (t_ps *)malloc((argc - 1) * sizeof(t_ps));
	st_b = (t_ps *)malloc((argc - 1) * sizeof(t_ps));
	memory_check (st_a, st_b);
	initialization_of_struct (st_a, argc, 1);
	initialization_of_struct (st_b, argc, 1);
	i = argc - 2;
	argv += (argc - 1);
	while (i >= 0)
	{
		if (come_only_dig_check(*argv) == -1 || integSize_check(*argv) == -1)
			ft_free_Nor_exit (st_a, st_b, 1);
		st_a[i].val_elem = ft_atoi(*argv--);
		st_a[i].empt_fl = 1;
		unrepeatability_check (st_a, st_b, argc, i);
		i--;
	}
	sorted_check (st_a, st_b, argc);
	start (st_a, st_b, argc);
	ft_free_Nor_exit (st_a, st_b, 2);
}

int	main(int argc, char **argv)
{
	initialization_of_stacks (argc, argv);
	return (0);
}
