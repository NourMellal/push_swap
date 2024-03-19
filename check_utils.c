/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:20:14 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:34:16 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
}
