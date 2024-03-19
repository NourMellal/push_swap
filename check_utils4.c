/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:23:34 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 21:25:44 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	list_length(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	push_to(t_node **stack_from, t_node **stack_to, char stack_name)
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
		ft_printf("p%c\n", stack_name);
		return ;
	}
	new_node->next = *stack_to;
	(*stack_to)->prev = new_node;
	*stack_to = new_node;
	pop(stack_from);
	ft_printf("p%c\n", stack_name);
}

void	reverse_rotate(t_node **head)
{
	t_node	*first;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *head;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
}

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}
