/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:49:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/20 13:27:10 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	sort_three(t_node **stack)
{
	int	position;

	position = find_max_pos(*stack);
	if (position == 0)
		ra(stack);
	else if (position == 1)
			rra(stack);
	if (!list_is_sorted(*stack))
		sa(stack);
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

int	pop(t_node **head)
{
	int		data;
	t_node	*tmp;

	if (!*head)
		return (-1);
	data = (*head)->n;
	tmp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
	return (data);
}

void	sort_bigs(t_node **stack_a, t_node **stack_b)
{
	int		*sorted_arr;
	int		i;
	t_node	*curr;
	t_ctrl	ctrl;
	int		size;

	curr = *stack_a;
	size = list_length(*stack_a);
	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
		return ;
	i = 0;
	while (i < size)
	{
		sorted_arr[i] = curr->n;
		i++;
		curr = curr->next;
	}
	quick_sort(sorted_arr, size);
	ctrl = define_ctrl_var(size, ft_sqrt(size));
	sorting_proc(stack_a, stack_b, sorted_arr, ctrl);
	free(sorted_arr);
	sorted_arr = NULL;
}
