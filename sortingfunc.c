/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/18 00:19:57 by nmellal          ###   ########.fr       */
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
	{
		push_to(stack_a, stack_b, 'b');
		push_to(stack_a, stack_b, 'b');
		sort_two_desc(stack_b);
		if (list_length(*stack_a) == 2)
		{
			sort_two_asc(stack_a);
			
		}
	}
	while (list_length(*stack_a) > 3)
	{
		;
	}
	sort_tree(stack_a);
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
