/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:40:26 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:14:15 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fixprob(t_node **stack_b, int pos, int num)
{
	if (list_length(*stack_b) - pos + 1 <= pos)
	{
		while ((*stack_b)->n != num)
			rrb(stack_b);
	}
	else
	{
		while ((*stack_b)->n != num)
			rb(stack_b);
	}
}

int	get_big(t_node *stack_b, int ret)
{
	int	p;
	int	n;
	int	i;

	i = 0;
	p = 0;
	n = stack_b->n;
	while (stack_b)
	{
		if (stack_b->n > n)
		{
			p = i;
			n = stack_b->n;
		}
		i++;
		stack_b = stack_b->next;
	}
	if (ret == 1)
		return (p);
	return (n);
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
