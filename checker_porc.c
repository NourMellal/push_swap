/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_porc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:00:21 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:43:01 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	start_proc2(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
	{
		if (*stack_b)
			delete_list(stack_b);
		display_error();
	}
}

void	start_proc(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			sa(stack_a);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb(stack_b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(stack_a, stack_b);
		else if (ft_strcmp(line, "pa\n") == 0)
			push_to2(stack_b, stack_a);
		else if (ft_strcmp(line, "pb\n") == 0)
			push_to2(stack_a, stack_b);
		else if (ft_strcmp(line, "ra\n") == 0)
			ra(stack_a);
		else
			start_proc2(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}
