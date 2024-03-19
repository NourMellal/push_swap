/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:13:17 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:13:39 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	its_correct_pos(t_node *stack_a, t_node *stack_b, int *arr, t_ctrl ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl.size)
	{
		if (stack_a->n == arr[i])
			break ;
		i++;
	}
	if (i > 0 && stack_b->n == arr[i - 1])
		return (1);
	return (0);
}

int	is_n_in_stack_a(t_node *stack_a, int *arr, t_ctrl ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl.size)
	{
		if (stack_a->n == arr[i])
			break ;
		i++;
	}
	while (stack_a)
	{
		if (i > 0 && arr[i - 1] == stack_a->n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	last_is_max(t_node *stack_a, int max)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	if (stack_a->n == max)
		return (1);
	return (0);
}

int	is_greater(int stack_b_val, t_node *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	if (stack_b_val > stack_a->n)
		return (1);
	return (0);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b, int *arr,
		t_ctrl ctrl)
{
	int	pos;
	int	np;

	pos = find_max_pos(*stack_b);
	to_top2(stack_b, stack_a, pos);
	while (*stack_b)
	{
		if (is_n_in_stack_a(*stack_a, arr, ctrl))
			rra(stack_a);
		else if (its_correct_pos(*stack_a, *stack_b, arr, ctrl))
			push_to(stack_b, stack_a, 'a');
		else if (last_is_max(*stack_a, arr[ctrl.size - 1])
			|| is_greater((*stack_b)->n, *stack_a))
		{
			push_to(stack_b, stack_a, 'a');
			ra(stack_a);
		}
		else
		{
			np = get_big(*stack_b, 1);
			fixprob(stack_b, np, get_big(*stack_b, 2));
		}
	}
}
