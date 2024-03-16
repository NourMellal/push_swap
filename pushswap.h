/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:19:24 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/16 01:43:12 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

typedef	struct s_control_var
{
	int size;
	int	div;
	int mid;
	int offset;
	int start;
	int end;
}				t_ctrl;

/* stacks/parsing implementation*/

t_node				*init_node(int data);
void				push(t_node **head, int data);
int					pop(t_node **head);
void				swap(t_node **head);
void				rotate(t_node **head);
void				reverse_rotate(t_node **head);
int					list_length(t_node *head);
void				delete_list(t_node **head);
void				display_list(t_node *head);
int					is_valid_num(char *str);
void				parsing_args(int ac, char **av, t_node **stack_a);
void				process_args(char *arg, t_node **stack_a);
void				add_to_stack(char *num_str, t_node **stack_a);
int					check_for_dup(t_node *stack_a);
void				push_to(t_node **stack_from, t_node **stack_to, char stack_name);
void				rr(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
void				display_error(void);



/* sorting implementation */

int		list_is_sorted(t_node *stack);
void	starting_point(t_node **stack_a, t_node **stack_b);
int		is_the_max(t_node *stack_a, t_node *stack_b);
int		is_the_min(t_node *stack_a, t_node *stack_b);
void	sort_two_desc(t_node **stack);
void	sort_two_asc(t_node **stack);
void	init_push(t_node **stack_a, t_node **stack_b);
void	push_back(t_node **stack_a, t_node **stack_b);
void sort_three(t_node **stack);
// void	sort_two(t_node **stack)
// int is_sorted(t_node *head)
int	find_min_position(t_node *stack, int *min);
void	sort_bigs(t_node **stack_a, t_node **stack_b);
void swap_ele(int *arr, int i, int j);
int partition(int *arr, int start, int end, void (*swap)(int [], int, int));
void quick_sort_helper(int *arr, int start, int end, int arr_size, void (*swap)(int[], int, int));
void quick_sort(int *arr, int arr_size, void (*swap)(int [], int, int));
void print_array(const int *array, size_t size);
int ft_sqrt(int nb);
t_ctrl	define_ctrl_var(int size, int div);
int		is_in_range(t_ctrl ctrl, int *arr, int elem);
int		find_elem_in_range(t_node *stack_a, int *arr, t_ctrl ctrl);
t_ctrl	update_ctrl(t_ctrl ctrl);
void	sorting_proc(t_node **stack_a, t_node **stack_b, int *arr, t_ctrl ctrl);
void	sort_bigs(t_node **stack_a, t_node **stack_b);


#endif /* PUSHSWAP */