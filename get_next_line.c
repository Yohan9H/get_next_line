/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:35:16 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/29 17:47:08 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	verif_end_line(char *tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		return (++i);
	return (0);
}

void	stock_rest_stop(int nb_read_char, char *tmp)
{
	static char	*stock_rest = NULL;

	stock_rest = &tmp[nb_read_char];
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	size_t	nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (nb_read > 0)
	{
		if (!rest)
		{
			rest = ft_strdup(buffer);
		}
		else
			
	}
	return ();
}

#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2,"error", 5);
		return (-1);
	}
	printf("My function : %s", get_next_line(fd));
	close(fd);
	return (0);
}