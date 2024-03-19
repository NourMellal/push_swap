/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:52:40 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:08:36 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

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
	if (list_is_sorted(stack_a))
	{
		delete_list(&stack_a);
		return (0);
	}
	starting_point(&stack_a, &stack_b);
	delete_list(&stack_a);
	return (0);
}
