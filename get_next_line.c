/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:12:09 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/05/20 16:16:25 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_store(int fd, char *store)
{
	char	*buffer;
	int		read_index;
	char	*temp_store;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(store), NULL);
	read_index = 1;
	while (!ft_strchr(store, '\n') && read_index != 0)
	{
		read_index = read(fd, buffer, BUFFER_SIZE);
		if (read_index == -1)
			return (free(buffer), free(store), NULL);
		buffer[read_index] = '\0';
		temp_store = ft_strjoin(store, buffer);
		if (!temp_store)
			return (free(buffer), free(store), NULL);
		free(store);
		store = temp_store;
	}
	free(buffer);
	return (store);
}

char	*get_clean_line(char *store)
{
	char	*line;
	char	*newline;
	size_t	len;
	size_t	i;

	if (!store || !*store)
		return (NULL);
	newline = ft_strchr(store, '\n');
	if (newline)
		len = (newline - store) + 1;
	else
		len = ft_strlen(store);
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = store[i];
		i++;
	}
	return (line);
}

char	*update_store(char *store)
{
	char	*new_store;
	char	*newline_pos;
	size_t	i;
	size_t	j;

	newline_pos = ft_strchr(store, '\n');
	if (!newline_pos)
	{
		free(store);
		return (NULL);
	}
	i = (newline_pos - store) + 1;
	new_store = (char *)ft_calloc(ft_strlen(store + i) + 1, sizeof(char));
	if (!new_store)
	{
		free(store);
		return (NULL);
	}
	j = 0;
	while (store[i])
		new_store[j++] = store[i++];
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_store(fd, store);
	if (!store || *store == '\0')
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = get_clean_line(store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	store = update_store(store);
	return (line);
}
