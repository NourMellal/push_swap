/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/16 05:00:31 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	starting_point(t_node **stack_a, t_node **stack_b)
{
	if (list_length(*stack_a) < 2)
		exit(1);
	if (list_length(*stack_a) == 2)
	{
		sa(stack_a);
		return ;
	}
	push_to(stack_a, stack_b, 'b');
	push_to(stack_a, stack_b, 'b');
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
