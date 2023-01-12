/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:00 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/12 12:25:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_clean(char *buff);
char	*ft_get_line(char *buff);
int		ft_strchr(char *buff);
char	*ft_strndup(char *buff, size_t end);
char	*ft_gnl_read(int fd, char *result);
char	*ft_get_clean(char *buff);
char	*ft_gnl_free(char *buff);

#endif