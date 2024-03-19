/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:23:46 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:31:30 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	parsing_args(ac, av, &stack_a);
	if (!check_for_dup(stack_a))
	{
		delete_list(&stack_a);
		display_error();
	}
	start_proc(&stack_a, &stack_b);
	if (!stack_b && list_is_sorted(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	delete_list(&stack_a);
	return (0);
}
