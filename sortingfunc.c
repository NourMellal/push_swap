/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/17 17:34:49 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	to_top(t_node **stack_a, t_node **stack_b, int position, int min_value)
{
	if ((list_length(*stack_a) / 2) < position + 1)
	{
		while (position--)
			rra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}
	else
	{
		while (position--)
			ra(stack_a);
		push_to(stack_a, stack_b, 'b');
	}
	(void)min_value;
}

void	to_top2(t_node **stack_b, t_node **stack_a, int position)
{
	if ((list_length(*stack_b) / 2) < position + 1)
	{
		while (position--)
			rra(stack_b);
		push_to(stack_b, stack_a, 'a');
	}
	else
	{
		while (position--)
			ra(stack_b);
		push_to(stack_b, stack_a, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int		position;
	t_node	*curr;
	int		min;

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
	position = 0;
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

void	swap_ele(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}

int	partition(int *arr, int start, int end, void (*swap)(int[], int, int))
{
	int	i;
	int	j;

	// [2, 1, 3, 4, 9, 8, 5<-]
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] < arr[end])
		{
			i++;
			swap(arr, i, j);
		}
		j++;
	}
	i++;
	if (arr[i] != arr[end])
		swap(arr, i, end);
	return (i);
}

void	quick_sort_helper(int *arr, int start, int end, int arr_size,
		void (*swap)(int[], int, int))
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(arr, start, end, swap);
	quick_sort_helper(arr, start, pivot - 1, arr_size, swap);
	quick_sort_helper(arr, pivot + 1, end, arr_size, swap);
}

void	quick_sort(int *arr, int arr_size, void (*swap)(int[], int, int))
{
	if (!arr || arr_size < 2)
		return ;
	quick_sort_helper(arr, 0, arr_size - 1, arr_size, swap);
}
void	print_array(const int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
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

t_ctrl	define_ctrl_var(int size, int div)
{
	t_ctrl	control;

	control.size = size;
	control.div = div;
	control.mid = size / 2 - 1;
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
	// if all elements not in the range (so we need to update ctrl)
	return (-1);
}
t_ctrl	update_ctrl(t_ctrl ctrl)
{
	ctrl.start -= ctrl.offset;
	if (ctrl.start < 0)
		ctrl.start = 0;
	ctrl.end += ctrl.offset;
	return (ctrl);
}
int	find_max_pos(t_node *stack_b)
{
	int	max;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	max = INT_MIN;
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

int	its_correct_pos(t_node *stack_a, t_node *stack_b, int *arr, t_ctrl ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl.size)
	{
		if (stack_a->n == arr[i])
			break ;
		i++;
	}
	if (stack_b->n == arr[i - 1] && i > 0)
		return (1);
	return (0);
}
int	is_n_in_stack_a(t_node *stack_a, int *arr, t_ctrl ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl.size)
	{
		if (stack_a->n == arr[i])
			break ;
		i++;
	}
	while (stack_a)
	{
		if (i > 0 && arr[i - 1] == stack_a->n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	last_is_max(t_node *stack_a, int max)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	// printf("\nstack a %d\n", stack_a->n);
	// printf("max %d\n\n", max);
	if (stack_a->n == max)
		return (1);
	return (0);
}

int	is_greater(int stack_b_val, t_node *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	// printf("stack a %d\n", stack_a->n);	tmp = *stack_b;
	// printf("stack_b_val %d\n\n", stack_b_val);
	if (stack_b_val > stack_a->n)
		return (1);
	return (0);
}
void	push_back_to_a(t_node **stack_a, t_node **stack_b, int *arr,
		t_ctrl ctrl)
{
	int	pos;

	pos = find_max_pos(*stack_b);
	to_top2(stack_b, stack_a, pos);
	// printf(" ========== >%d\n", arr[ctrl.size - 1]);
	while (*stack_b)
	{
		if (is_n_in_stack_a(*stack_a, arr, ctrl))
			rra(stack_a);
		else if (its_correct_pos(*stack_a, *stack_b, arr, ctrl))
			push_to(stack_b, stack_a, 'a');
		else if (last_is_max(*stack_a, arr[ctrl.size - 1])
			|| is_greater((*stack_b)->n, *stack_a))
		{
			push_to(stack_b, stack_a, 'a');
			ra(stack_a);
		}
		else
			rb(stack_b);
	}
}
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
			to_top(stack_a, stack_b, pos, 0);
			if ((*stack_b)->n < arr[ctrl.mid])
				rb(stack_b);
		}
		else
			ctrl = update_ctrl(ctrl);
	}
	push_back_to_a(stack_a, stack_b, arr, ctrl);
	while (!list_is_sorted(*stack_a))
		rra(stack_a);
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
	quick_sort(sorted_arr, size, swap_ele);
	ctrl = define_ctrl_var(size, ft_sqrt(size));
	sorting_proc(stack_a, stack_b, sorted_arr, ctrl);
	free(sorted_arr);
	sorted_arr = NULL;
}

void	starting_point(t_node **stack_a, t_node **stack_b)
{
	if (list_length(*stack_a) == 2)
		sa(stack_a);
	else if (list_length(*stack_a) == 3)
		sort_three(stack_a);
	else if (list_length(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		sort_bigs(stack_a, stack_b);
}

void	sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->n;
	middle = (*stack)->next->n;
	bottom = (*stack)->next->next->n;
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
}