/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlistfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:22 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/16 18:18:43 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}
void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
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
	exit (1);
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
void	push_to(t_node **stack_from, t_node **stack_to, char stack_name)
{
	if (!*stack_from)
		return ;
	push(stack_to, (*stack_from)->n);
	pop(stack_from);
	ft_printf("p%c\n", stack_name);
}


void	swap(t_node **head)
{
	t_node *first, *second;
	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	rotate(t_node **head)
{
	t_node *first, *last;
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

void	reverse_rotate(t_node **head)
{
	t_node	*first;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *head;
	(*head)->prev = first;
	first->prev = NULL;
	*head = first;
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
	t_node *current, *next;
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
		ft_printf("%d ", head->n);
		head = head->next;
	}
	ft_printf("\n");
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
		process_args(av[i], stack_a);
		i++;
	}
}
// if (!is_valid_num(num_str))
// {
// 	ft_putstr_fd("oops, i think some args are not numbers\n", 2);
// 	exit(1) ;
// }

// push(stack_a, ft_atoi(num_str));
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

void	add_to_stack(char *num_str, t_node **stack_a)
{
	if (!is_valid_num(num_str))
		display_error();
	push(stack_a, ft_atoi(num_str));
}
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	parsing_args(argc, argv, &stack_a);
	if (!check_for_dup(stack_a))
	{
		delete_list(&stack_a);
		display_error();
	}
	if ( (stack_a))
	{
		delete_list(&stack_a);
		return (0);
	}
	// to be continue
	display_list(stack_a);
	starting_point(&stack_a, &stack_b);
	display_list(stack_a);
	delete_list(&stack_a);
	return (0);
}
