/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 01:07:15 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	to_top(t_node **stack_a, t_node **stack_b, int position)
{
	if ((list_length(*stack_a) / 2) < position + 1)
	{
		while (position++ < list_length(*stack_a))
			rra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}
	else
	{
		while (position--)
			ra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}
}

void	to_top2(t_node **stack_b, t_node **stack_a, int position)
{
	if ((list_length(*stack_b) / 2) < position + 1)
	{
		while (position++ < list_length(*stack_b))
			rrb(stack_b);
		push_to(stack_b, stack_a, 'a');
	}
	else
	{
		while (position--)
			rb(stack_b);
		push_to(stack_b, stack_a, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	position;

	while (list_length(*stack_a) > 3)
	{
		position = find_min_position(*stack_a);
		to_top(stack_a, stack_b, position);
	}
	sort_three(stack_a);
	while (*stack_b)
		push_to(stack_b, stack_a, 'a');
}

int	find_min_position(t_node *stack)
{
	int	position;
	int	i;
	int	min;

	min = INT_MAX;
	i = 0;
	position = 0;
	while (stack)
	{
		if (stack->n < min)
		{
			position = i;
			min = stack->n;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int	list_is_sorted(t_node *stack)
{
	t_node	*nxt;

	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		nxt = stack->next;
		if (stack->n > nxt->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
