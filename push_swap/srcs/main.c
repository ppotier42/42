/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:18:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/13 15:09:42 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i == 2)
		exit (1);
}

t_stack	*fill_value(int ac, char **av)
{
	t_stack	*a;
	int		nb;
	char	**args;

	nb = 0;
	a = NULL;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = ++av;
	if (!args)
		return (NULL);
	while (*args)
	{
		nb = ft_atoi(*args);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(&a, NULL);
		stack_add(&a, ft_stack_new(nb));
		args++;
	}
	free(*args);
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
	ft_check_av(av);
	if (!ft_check_input(ac, av))
		ft_error(NULL, NULL);
	b = NULL;
	a = fill_value(ac, av);
	stack_size = get_stack_size(a);
	give_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
