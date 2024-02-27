/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/24 19:17:09 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	starting_point(t_node **stack_a, t_node **stack_b)
{
	if (list_length(*stack_a) == 2)
	{
		sa(stack_a);
		return ;
	}
	if (list_length(*stack_a) > 3)
		init_push(stack_a, stack_b);
	while (list_length(*stack_a) > 3)
	{
		if (is_the_max(*stack_a, *stack_b))
			push_to(stack_a, stack_b, 'b');
		else if (is_the_min(*stack_a, *stack_b))
		{
			push_to(stack_a, stack_b, 'b');
			rb(stack_b);
		}
	}
	sort_three(stack_a);
	push_back(stack_a, stack_b);
}

void	init_push(t_node **stack_a, t_node **stack_b)
{
	push_to(stack_a, stack_b, 'b');
	push_to(stack_a, stack_b, 'b');
	sort_two_desc(stack_b);
	if (list_length(*stack_a) == 2)
		sort_two_asc(stack_a);
	else if (list_length(*stack_a) == 3)
		sort_three(stack_a);
	return ;
}
void sort_three(t_node **stack)
{
	int top = (*stack)->n;
	int middle = (*stack)->next->n;
	int bottom = (*stack)->next->next->n;

	if (top > middle && middle < bottom && top < bottom)
	{
		// Case: 2 1 3 -> Only need to swap the top two.
		sa(stack);
	}
	else if (top > middle && middle > bottom)
	{
		// Case: 3 2 1 -> Swap the top two, then rotate down.
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
	{
		// Case: 3 1 2 -> Rotate up.
		ra(stack);
	}
	else if (top < middle && middle > bottom && top < bottom)
	{
		// Case: 1 3 2 -> Swap the top two, then rotate up.
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
	{
		// Case: 2 3 1 -> Rotate down.
		rra(stack);
	}
	// If none of the above conditions are met, the stack is already sorted (1 2 3).
}

void	sort_two_asc(t_node **stack)
{
	if ((*stack)->n > (*stack)->next->n)
		sb(stack);
}

void	sort_two_desc(t_node **stack)
{
	if ((*stack)->n < (*stack)->next->n)
		sb(stack);
}

int	is_the_min(t_node *stack_a, t_node *stack_b)
{
	if (!stack_a || !stack_b)
		return (-1);
	while(stack_b)
	{
		if (stack_b->n < stack_a->n)
			//its not the minimum
			return (0);
		stack_b = stack_b->next;
	}
	//it is the minimum
	return (1);
}
int	is_the_max(t_node *stack_a, t_node *stack_b)
{
	if (!stack_a || !stack_b)
		return (-1);
	while(stack_b)
	{
		if (stack_b->n > stack_a->n)
			//its not the max
			return (0);
		stack_b = stack_b->next;
	}
	//it is the minimum
	return (1);
}

int	list_is_sorted(t_node *stack)
{
	t_node *nxt;

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

// int	is_sorted(t_node *head)
// {
// 	while (head && head->next)
// 	{
// 		if (head->n > head->next->n)
// 			return (0);
// 		head = head->next;
// 	}
// 	return (1);
// }
