/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:35 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:13:03 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_push_swap
{
	int	empt_fl;
	int	val_elem;
	int	up_count_rotate;
	int	up_count_reverse;
	int	pl_count_rotate;
	int	pl_count_reverse;
	int	fl_up_rotate;
	int	fl_up_reverse;
	int	fl_pl_rotate;
	int	fl_pl_reverse;
	int	iter_sum;
}		t_ps;

int		integSize_check(char *argv);
int		come_only_dig_check(char *argv);
void	unrepeatability_check(t_ps *st_a, t_ps *st_b, int argc, int i);
void	sorted_check(t_ps *st_a, t_ps *st_b, int argc);
void	memory_check(t_ps *st_a, t_ps *st_b);

void	initialization_of_struct(t_ps *stack, int argc, int fl);
void	ft_free_Nor_exit(t_ps *st_a, t_ps *st_b, int fl);

void	initialization_of_stacks(int argc, char **argv);

void	swap(t_ps *stack, int count);
void	push(t_ps *st_1, t_ps *st_2, int argc, char fl);
void	rotate(t_ps *stack, int argc, char fl);
void	reverse_rotate(t_ps *stack, int argc, char fl);

void	push_shell(char fl);
void	rotate_a_b(t_ps *st_a, t_ps *st_b, int argc, char fl);
void	rotate_shell(char fl);
void	reverse_rotate_a_b(t_ps *st_a, t_ps *st_b, int argc, char fl);
void	rev_rot_shell(char fl);

int		el_num(t_ps *stack, int argc);
int		the_least_elem(t_ps *stack, int argc);
int		the_greatest_elem(t_ps *stack, int argc);
int		optimal_elem(t_ps *stack, int argc);

void	up_operation_counter(t_ps *stack, int argc, int num_elem);
void	place_operation_counter(t_ps *st_a, t_ps *st_b, int argc, int iter_b);

void	start(t_ps *st_a, t_ps *st_b, int argc);
void	algorithm_first_step(t_ps *st_a, t_ps *st_b, int argc);
int		algorithm_second_step(t_ps *st_a, t_ps *st_b, int argc);
void	algorithm_fourth_step(t_ps *st_a, int argc);

void	algorithm_third_step(t_ps *st_a, t_ps *st_b, int argc);
void	Bre_Are(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b);
void	Bro_Aro(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b);
void	BreAro_BreA_BAro(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b);
void	BroAre_BroA_BAre(t_ps *st_a, t_ps *st_b, int argc, int optimal_el_b);

void	stack_on_free_elems(t_ps *st_a, int argc);
void	four_N_five(t_ps *st_a, t_ps *st_b, int argc);
void	small_stacks(t_ps *st_a, t_ps *st_b, int argc);

#endif
