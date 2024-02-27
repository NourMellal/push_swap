/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:08:35 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 12:33:22 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	if ((stack_b))
		return ;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	ft_lstclear(&stack_a);
	exit(0);
}

void	ft_is_doubled_or_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == 2147483648)
			errors(2, &stack);
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				errors(2, &stack);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (str[0] == '\0' || result * sign > INT_MAX || \
		str[i] != '\0' || result * sign < INT_MIN || \
		((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		|| (i > 11))
		return (2147483648);
	return ((result * sign));
}
