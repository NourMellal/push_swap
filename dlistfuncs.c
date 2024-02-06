/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlistfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:22 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/06 16:11:13 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	push(t_node **head, int data)
{
	t_node *newnode;
	t_node *curr;

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
int	pop(t_node **head)
{
	int data;
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
void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	/* start swapping */
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*head = second;
}
void	rotate(t_node **head)
{
	t_node *first;
	t_node *last;

	if (!*head || !(*head)->next)
		return ;
	last = *head;
	first = *head;
	while (last->next)
		last = last->next;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
void reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*first;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*head = last;
}
int	list_length(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	delete_list(t_node **head)
{
	t_node *current;
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
void	display_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d", head->n);
		if (head->next)
			ft_printf(" ");
		head = head->next;
	}
	ft_printf("\n");
}

int	is_valid_num(char *str)
{
	int	i;
	int j;

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
		if (!ft_isdigit(i[str])) /* +000002056008454854*/
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
void	parsing_args(int ac, char **av, t_node **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (*av[i] == '\0')
			i++;
		else
		{
			process_args(av[i], stack_a);
			i++;
		}
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
		while (numbrs[j])
		{
			// printf("%s\n", numbrs[j]);
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

void	add_to_stack(char *num_str, t_node **stack_a)
{

	if (!is_valid_num(num_str))
	{
		ft_putstr_fd("oops, i think some args are not numbers\n", 2);
		exit(1) ;
	}

	push(stack_a, ft_atoi(num_str));
}

int main(int argc, char **argv)
{
	t_node *stack_a;
	stack_a = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./push_swap n1 n2 ...\n", 2);
		exit (1);
	}
	parsing_args(argc, argv, &stack_a);
	if (!check_for_dup(stack_a));
	{
		delete_list(&stack_a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	// to be continue
	display_list(stack_a);
	delete_list(&stack_a);
	return 0;
}
