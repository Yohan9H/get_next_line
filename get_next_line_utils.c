/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:35:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/29 16:55:43 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len_s1;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1);
	cpy = (char *)malloc((len_s1 + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i] != '\n' && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}


char	*ft_strjoin(const char *s1, const char *s2, int verif)
{
	char	*str;
	size_t	len_total;
	size_t	i;

	i = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2) + verif + 1;
	str = (char *)malloc(len_total * sizeof(char));
	if (!str)
		return (NULL);
	len_total = 0;
	while (s1[i] && s1[i] != '\n')
	{
		str[len_total++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		str[len_total++] = s2[i];
		i++;
	}
	if (verif == 1)
		str[len_total] = '\n';
	str[++len_total] = '\0';
	return (str);
}
