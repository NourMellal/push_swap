/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:01:35 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 21:15:56 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*destalloc(char *str)
{
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*str;

	dest = destalloc(dest);
	if (!dest || !src)
		return (NULL);
	str = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (dest[++i])
		str[i] = dest[i];
	j = 0;
	while (src[j])
	{
		str[i + j] = src[j];
		j++;
	}
	str[i + j] = '\0';
	free(dest);
	return (str);
}

int	charsearch(char *buffer, char c)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
