/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:26:02 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:48:00 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	add_to_stack(char *num_str, t_node **stack_a)
{
	if (!is_valid_num(num_str))
	{
		delete_list(stack_a);
		display_error();
	}
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
