/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:01:35 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 21:16:08 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*return_and_free(size_t len, char *buffer, char *str)
{
	free(str);
	if (len == 0)
		return (buffer);
	else
		return (NULL);
}

char	*readline(int fd, char *buffer, ssize_t len)
{
	char	*str;
	char	*temp;

	str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (charsearch(buffer, '\n') == -1)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len <= 0)
			return (return_and_free(len, buffer, str));
		str[len] = '\0';
		temp = ft_strcat(buffer, str);
		if (!temp)
		{
			free(str);
			return (NULL);
		}
		buffer = temp;
	}
	free(str);
	return (buffer);
}

char	*process_line(char *buffer)
{
	int		i;
	int		len;
	char	*str;

	if (!*buffer)
		return (NULL);
	len = charsearch(buffer, '\n');
	if (len < 0)
		len = ft_strlen(buffer);
	str = malloc(sizeof(char) * len + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = buffer[i];
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*go_to_next_line(char *buffer)
{
	int		i;
	char	*new_buff;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!new_buff)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[++i])
		new_buff[j++] = buffer[i];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	ssize_t		len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	len = 1;
	buffer = readline(fd, buffer, len);
	if (!buffer)
		return (NULL);
	res = process_line(buffer);
	buffer = go_to_next_line(buffer);
	return (res);
}

// int	main(void)
// {
// 	int		filed;
// 	char	*s;

// 	filed = open("aden.txt", O_RDWR);
// 	s = get_next_line(filed);
// 	while (s)
// 	{
// 		printf("%s\n", s);
// 		free(s);
// 		s = get_next_line(filed);
// 		sleep(2);
// 	}
// 	return (0);
// }
