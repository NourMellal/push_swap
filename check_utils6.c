/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:40:29 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:43:18 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_to2(t_node **stack_from, t_node **stack_to)
{
	t_node	*curr;
	t_node	*new_node;

	if (!*stack_from)
		return ;
	curr = *stack_from;
	new_node = init_node(curr->n);
	if (!*stack_to)
	{
		*stack_to = new_node;
		pop(stack_from);
		return ;
	}
	new_node->next = *stack_to;
	(*stack_to)->prev = new_node;
	*stack_to = new_node;
	pop(stack_from);
}
