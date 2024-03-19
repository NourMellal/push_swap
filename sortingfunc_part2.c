/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunc_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:09:12 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 02:04:38 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_ele(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}

int	partition(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	tmp;

	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] < arr[end])
		{
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
		j++;
	}
	i++;
	if (arr[i] != arr[end])
	{
		tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
	return (i);
}

void	quick_sort_helper(int *arr, int start, int end, int arr_size)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(arr, start, end);
	quick_sort_helper(arr, start, pivot - 1, arr_size);
	quick_sort_helper(arr, pivot + 1, end, arr_size);
}

void	quick_sort(int *arr, int arr_size)
{
	if (!arr || arr_size < 2)
		return ;
	quick_sort_helper(arr, 0, arr_size - 1, arr_size);
}

void	print_array(const int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			ft_printf(", ");
		ft_printf("%d", array[i]);
		++i;
	}
	ft_printf("\n");
}
