/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:09:42 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:12:39 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_ctrl	define_ctrl_var(int size, int div)
{
	t_ctrl	control;

	control.size = size;
	control.div = div;
	control.mid = size / 2;
	control.offset = size / div;
	control.start = control.mid - control.offset;
	control.end = control.mid + control.offset;
	return (control);
}

int	is_in_range(t_ctrl ctrl, int *arr, int elem)
{
	int	i;

	i = ctrl.start;
	while (i <= ctrl.end)
	{
		if (elem == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_elem_in_range(t_node *stack_a, int *arr, t_ctrl ctrl)
{
	int	i;
	int	position;

	position = 0;
	while (stack_a)
	{
		i = ctrl.start;
		while (i <= ctrl.end)
		{
			if (arr[i] == stack_a->n)
				return (position);
			i++;
		}
		stack_a = stack_a->next;
		position++;
	}
	return (-1);
}

t_ctrl	update_ctrl(t_ctrl ctrl)
{
	ctrl.start -= ctrl.offset;
	if (ctrl.start < 0)
		ctrl.start = 0;
	ctrl.end += ctrl.offset;
	if (ctrl.end > ctrl.size - 1)
		ctrl.end = ctrl.size - 1;
	return (ctrl);
}

int	find_max_pos(t_node *stack_b)
{
	int	max;
	int	pos;
	int	i;

	max = INT_MIN;
	pos = 0;
	i = 0;
	while (stack_b)
	{
		if (stack_b->n > max)
		{
			max = stack_b->n;
			pos = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (pos);
}
