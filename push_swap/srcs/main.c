/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:18:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/21 14:50:20 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i == 1)
	{
		ft_putstr_fd("Error\n", 2);
		// ft_free(av);
		// return (0);
		exit (1);
	}
	return (1);
}

t_stack	*fill_value(int ac, char **av)
{
	t_stack	*a;
	int		nb;
	char	**args;

	nb = 0;
	a = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!*args)
			return (NULL);
	}
	else
		args = ++av;
	if (!ft_check_av(args))
		return (NULL);
	while (*args)
	{
		nb = ft_atoi(*args);
		stack_add(&a, ft_stack_new(nb));
		args++;
	}
	// ft_free(args);
	return (a);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **a, t_stack **b, int size)
{
	(void)b;
	if (size == 2 && !ft_is_sorted(*a))
		do_sa(a);
	else if (size == 3)
		quick_sort(a);
	else if (size > 3 && !ft_is_sorted(*a))
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (ac < 2)
		return (1);
	if (!ft_check_input(ac, av))
		ft_putstr_fd("Error\n", 2);
	// ft_error(NULL, NULL);
	b = NULL;
	a = fill_value(ac, av);
	stack_size = get_stack_size(a);
	give_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
