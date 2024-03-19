/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:26:27 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/19 23:48:33 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* BONUS */

#ifndef CHECKER_H
# define CHECKER_H

# include "pushswap.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*destalloc(char *str);
char	*ft_strcat(char *dest, char *src);
int		charsearch(char *buffer, char c);
char	*return_and_free(size_t len, char *buffer, char *str);
char	*readline(int fd, char *buffer, ssize_t len);
char	*process_line(char *buffer);
char	*go_to_next_line(char *buffer);
char	*get_next_line(int fd);
void	start_proc(t_node **stack_a, t_node **stack_b);
int		ft_strcmp(char *s1, char *s2);
void	start_proc2(t_node **stack_a, t_node **stack_b, char *line);
void	push_to2(t_node **stack_from, t_node **stack_to);

#endif
