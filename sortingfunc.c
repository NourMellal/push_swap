/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/12 12:56:55 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	to_top(t_node **stack_a, t_node **stack_b, int position, int min_value)
{
	if ((list_length(*stack_a) / 2) < position + 1)
	{
		while ((*stack_a)->n != min_value)
			rra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}
	else
	{
		while ((*stack_a)->n != min_value)
			ra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}

}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int position;
	t_node	*curr;
	int min;

	min = 0;
	curr = *stack_a;
	while (list_length(curr) > 3)
	{
		position = find_min_position(*stack_a, &min);
		to_top(stack_a, stack_b, position, min);
		curr = *stack_a;
	}
	sort_three(stack_a);
	push_to(stack_b, stack_a, 'a');
	push_to(stack_b, stack_a, 'a');

}

int	find_min_position(t_node *stack, int *min)
{
	int	position;
	int	i;

	*min = INT_MAX;
	i = 0;
	while (stack)
	{
		if (stack->n < *min)
		{
			position = i;
			*min = stack->n;
		}
		stack = stack->next;
		i++;
	}
	return (position);
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



void	sort_bigs(t_node **stack_a)
{
	int *sorted_arr;
	int	i;
	t_node	*curr;

	curr = *stack_a;
	sorted_arr = malloc(sizeof(int) * list_length(*stack_a));
	i = 0;
	while (i < list_length(*stack_a))
	{
		sorted_arr[i] = curr->n;
		i++;
		curr = curr->next;
	}
}

void	starting_point(t_node **stack_a, t_node **stack_b)
{
	if (list_length(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	else if (list_length(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	sort_bigs(stack_a);
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

// void	sort_two_asc(t_node **stack)
// {
// 	if ((*stack)->n > (*stack)->next->n)
// 		sb(stack);
// }

// void	sort_two_desc(t_node **stack)
// {
// 	if ((*stack)->n < (*stack)->next->n)
// 		sb(stack);
// }

// int	is_the_min(t_node *stack_a, t_node *stack_b)
// {
// 	if (!stack_a || !stack_b)
// 		return (-1);
// 	while(stack_b)
// 	{
// 		if (stack_b->n < stack_a->n)
// 			//its not the minimum
// 			return (0);
// 		stack_b = stack_b->next;
// 	}
// 	//it is the minimum
// 	return (1);
// }
// int	is_the_max(t_node *stack_a, t_node *stack_b)
// {
// 	if (!stack_a || !stack_b)
// 		return (-1);
// 	while(stack_b)
// 	{
// 		if (stack_b->n > stack_a->n)
// 			//its not the max
// 			return (0);
// 		stack_b = stack_b->next;
// 	}
// 	//it is the minimum
// 	return (1);
// }



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
