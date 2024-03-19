/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlistfuncs_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:22 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 01:08:21 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

t_node	*init_node(int data)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->n = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	display_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
