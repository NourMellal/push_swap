/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlistfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:22 by nmellal           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/06 16:11:13 by nmellal          ###   ########.fr       */
=======
/*   Updated: 2024/02/04 17:11:29 by nmellal          ###   ########.fr       */
>>>>>>> 6534a4bf7a626fba0ae258bda0b9e36ae1d95365
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node *init_node(int data)
{
    t_node *newnode;
    newnode = malloc(sizeof(t_node));
    if (!newnode)
        return (NULL);
    newnode->n = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return (newnode);
}

void push(t_node **head, int data)
{
    t_node *newnode = init_node(data);
    if (!newnode)
        return;
    if (!*head)
    {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;
}

int pop(t_node **head)
{
    int data;
    t_node *tmp;
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

void swap(t_node **head, char stack_name)
{
    t_node *first, *second;
    if (!*head || !(*head)->next)
        return;
    first = *head;
    second = first->next;
    first->next = second->next;
    second->next = first;
    second->prev = first->prev;
    first->prev = second;
    if (first->next)
        first->next->prev = first;
    *head = second;
    ft_printf("s%c\n", stack_name);
}

void rotate(t_node **head, char stack_name)
{
    t_node *first, *last;
    if (!*head || !(*head)->next)
        return;
    first = *head;
    last = *head;
    while (last->next)
        last = last->next;
    *head = first->next;
    (*head)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
    ft_printf("r%c\n", stack_name);
}

void reverse_rotate(t_node **head, char stack_name)
{
    t_node *first;
    if (!*head || !(*head)->next)
        return;
    first = *head;
    while (first->next)
        first = first->next;
    first->prev->next = NULL;
    first->next = *head;
    (*head)->prev = first;
    first->prev = NULL;
    *head = first;
    ft_printf("rr%c\n", stack_name);
}

int list_length(t_node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

void delete_list(t_node **head)
{
<<<<<<< HEAD
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
=======
    t_node *current, *next;
    current = *head;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
>>>>>>> 6534a4bf7a626fba0ae258bda0b9e36ae1d95365
}

void display_list(t_node *head)
{
    while (head)
    {
        ft_printf("%d ", head->n);
        head = head->next;
    }
    ft_printf("\n");
}

int is_valid_num(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void parsing_args(int ac, char **av, t_node **stack_a)
{
    int i = 1;
    while (i < ac)
    {
        if (*av[i] != '\0')
            process_args(av[i], stack_a);
        i++;
    }
}

<<<<<<< HEAD
	if (!is_valid_num(num_str))
	{
		ft_putstr_fd("oops, i think some args are not numbers\n", 2);
		exit(1) ;
	}

	push(stack_a, ft_atoi(num_str));
=======
void process_args(char *arg, t_node **stack_a)
{
    char **numbrs;
    int j = 0;
    if (ft_strchr(arg, ' '))
    {
        numbrs = ft_split(arg, ' ');
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
>>>>>>> 6534a4bf7a626fba0ae258bda0b9e36ae1d95365
}

void add_to_stack(char *num_str, t_node **stack_a)
{
    if (!is_valid_num(num_str))
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    push(stack_a, ft_atoi(num_str));
}
int main(int argc, char **argv)
{
	t_node *stack_a;
	// t_node *stack_b;

	// stack_b = NULL;
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