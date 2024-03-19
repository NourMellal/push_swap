/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:21:42 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:35:09 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_for_dup(t_node *stack_a)
{
	t_node	*curr;
	t_node	*nxt;

	if (!stack_a)
		return (1);
	curr = stack_a;
	while (curr)
	{
		nxt = curr->next;
		while (nxt)
		{
			if (curr->n == nxt->n)
				return (0);
			nxt = nxt->next;
		}
		curr = curr->next;
	}
	return (1);
}

void	delete_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	parsing_args(int ac, char **av, t_node **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		process_args(av[i], stack_a);
		i++;
	}
}

void	process_args(char *arg, t_node **stack_a)
{
	char	**numbrs;
	int		j;

	j = 0;
	if (ft_strchr(arg, ' '))
	{
		numbrs = ft_split(arg, ' ');
		if (!numbrs)
		{
			delete_list(stack_a);
			free(numbrs);
			display_error();
		}
		while (numbrs[j])
		{
			add_to_stack(numbrs[j], stack_a);
			free(numbrs[j]);
			j++;
		}
		free(numbrs);
	}
	else
	{
		add_to_stack(arg, stack_a);
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
