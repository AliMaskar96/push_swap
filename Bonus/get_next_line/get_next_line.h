/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:38:24 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/25 11:37:17 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif