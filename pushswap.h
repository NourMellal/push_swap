/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:24 by nmellal           #+#    #+#             */
/*   Updated: 2024/02/04 16:59:29 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
typedef struct s_node
{

	int			n;
	struct		s_node	*next;
	struct		s_node	*prev;

}		t_node;

/* stacks/parsing implementation*/

t_node *init_node(int data);
void push(t_node **head, int data);
int pop(t_node **head);
void swap(t_node **head, char stack_name);
void rotate(t_node **head, char stack_name);
void reverse_rotate(t_node **head, char stack_name);
int list_length(t_node *head);
void delete_list(t_node **head);
void display_list(t_node *head);
int is_valid_num(char *str);
void parsing_args(int ac, char **av, t_node **stack_a);
void process_args(char *arg, t_node **stack_a);
void add_to_stack(char *num_str, t_node **stack_a);

/* sorting implementation */

// void	sort_two(t_node **stack)
// int is_sorted(t_node *head)

#endif /* PUSHSWAP */