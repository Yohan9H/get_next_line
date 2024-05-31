/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:35:16 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/31 16:53:04 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*add_line_buffer(char *buffer, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, line);
	free(buffer);
	// if (!tmp)
	// 	return (free(line), NULL);
	return (tmp);
}

char	*read_file_and_maj_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = add_line_buffer(stash, buffer); 
		if (ft_strchr(buffer, '\n'))
			break ;
		//ft_bzero(buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (stash);
}

char	*take_line_to_stash(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*del_line_to_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	j = 0;
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file_and_maj_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = take_line_to_stash(buffer);
	buffer = del_line_to_stash(buffer);
	if (buffer == NULL)
		return (free(buffer), NULL);
	return (line);
}

// #include <fcntl.h>
// #include <stdlib.h>
// int main()
// {
//     int fd;
//     char *line;
// 	int	count = 1;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("count[%d] : %s", count++, line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }