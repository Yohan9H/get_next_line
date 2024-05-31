/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:35:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/31 11:28:46 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || s[0] == '\0') // test
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_total;
	size_t	i;

	i = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len_total * sizeof(char));
	if (!str)
		return (NULL);
	len_total = 0;
	while (s1[i])
	{
		str[len_total] = s1[i];
		len_total++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_total] = s2[i];
		len_total++;
		i++;
	}
	str[len_total] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	cpy_c;
	int		i;

	i = 0;
	cpy_c = (char)c;
	while (s[i])
	{
		if (s[i] == cpy_c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb * size < size && nmemb * size != 0)
		return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cpy_s;
	size_t			i;

	cpy_s = (unsigned char *)s;
	i = 0;
	while (i != n)
	{
		cpy_s[i] = '\0';
		i++;
	}
}
