/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:59:31 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:16:03 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_proc(t_node **stack_a, t_node **stack_b, int *arr, t_ctrl ctrl)
{
	int	pos;

	while (*stack_a)
	{
		if (is_in_range(ctrl, arr, (*stack_a)->n))
		{
			push_to(stack_a, stack_b, 'b');
			if ((*stack_b)->n < arr[ctrl.mid])
				rb(stack_b);
		}
		else if (find_elem_in_range(*stack_a, arr, ctrl) != -1)
		{
			pos = find_elem_in_range(*stack_a, arr, ctrl);
			to_top(stack_a, stack_b, pos);
			if ((*stack_b)->n < arr[ctrl.mid])
				rb(stack_b);
		}
		else
		{
			ctrl = update_ctrl(ctrl);
		}
	}
	push_back_to_a(stack_a, stack_b, arr, ctrl);
	while (!list_is_sorted(*stack_a))
		rra(stack_a);
}

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt <= nb)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (sqrt);
}

void	add_to_stack(char *num_str, t_node **stack_a)
{
	if (!is_valid_num(num_str))
		display_error();
	push(stack_a, ft_atoi(num_str));
}

int	is_valid_num(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == 32 || (i[str] >= 9 && i[str] <= 13))
		i++;
	if (i[str] == '-' || i[str] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (i[str] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(i[str]))
			return (0);
		i++;
		j++;
	}
	if (ft_strlen(&str[i - j]) > 10)
		return (0);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	return (1);
}

void	push(t_node **head, int data)
{
	t_node	*newnode;
	t_node	*curr;

	newnode = init_node(data);
	if (!newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = newnode;
	newnode->prev = curr;
}
