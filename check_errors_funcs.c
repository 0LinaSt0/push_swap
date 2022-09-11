/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:09 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 20:58:09 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check for arguments don't be bigger than an int*/
int	integSize_check(char *argv)
{
	int		int_argv;
	int		i;
	char	*buf;

	i = 0;
	int_argv = ft_atoi(argv);
	buf = ft_itoa(int_argv);
	if (*argv == '+')
		argv++;
	while (argv[i])
	{
		if (buf[i] == argv[i])
			i++;
		else
		{
			free (buf);
			return (-1);
		}
	}
	free (buf);
	return (1);
}

/*Check for all agruments be an int*/
int	come_only_dig_check(char *argv)
{
	if (*argv == '+' || *argv == '-')
		argv++;
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
			argv++;
		else
			return (-1);
	}
	return (1);
}

/* check on unrepeatability elements of input stack A */
void	unrepeatability_check(t_ps *st_a, t_ps *st_b, int argc, int i)
{
	int	check;

	check = 0;
	if (i != (argc - 2))
	{
		check = i + 1;
		while (check <= (argc - 2))
		{
			if (st_a[i].val_elem == st_a[check].val_elem)
				ft_free_Nor_exit (st_a, st_b, 1);
			check++;
		}
	}
}

/* check on sorted elements of input stack A */
void	sorted_check(t_ps *st_a, t_ps *st_b, int argc)
{
	int	temp;

	temp = 0;
	while (st_a[temp].val_elem < st_a[temp + 1].val_elem && temp <= (argc - 2))
		temp++;
	if (temp == (argc - 2))
		ft_free_Nor_exit (st_a, st_b, 3);
}

/* check for memory allocation */
void	memory_check(t_ps *st_a, t_ps *st_b)
{
	if (st_a == NULL && st_b == NULL)
		ft_free_Nor_exit (st_a, st_b, 'N');
	else if (st_a == NULL)
		ft_free_Nor_exit (st_a, st_b, 'a');
	else if (st_b == NULL)
		ft_free_Nor_exit (st_a, st_b, 'b');
}
