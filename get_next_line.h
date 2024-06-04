/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:33:49 by yohurteb          #+#    #+#             */
/*   Updated: 2024/06/04 10:22:54 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

void	*ft_calloc(size_t nmemb, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif