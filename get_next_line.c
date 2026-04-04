/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:12:09 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/04 04:06:49 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


 char *read_store( int fd, char *store)
{
    char *buffer;
    int read_index;

    buffer=(char *)ft_calloc((BUFFER_SIZE + 1),sizeof(char));
    if (!buffer)
    {
        return (NULL);
    }
    
    read_index=1;
    while (!ft_strchr(store,'\n') && read_index !=0)
    {
        read_index=read(fd , buffer , BUFFER_SIZE);
        if (read_index == -1)
        {
            free(buffer);
            return (NULL);
        }
        
        buffer[read_index]='\0';
        store=ft_strjoin(store,buffer);
    }
    free(buffer);
    return(store);
}

char	*get_clean_line(char *store)
{
    char	*line;
	char	*newline;
	size_t	len;

	if (!store || !*store)
        return(NULL);
    


	newline = ft_strchr(store, '\n');
	
	if (newline)
		len = (newline - store) + 1;
	else
		len = ft_strlen(store);

	line = (char *)ft_calloc(len + 1, sizeof(char));


	if (!line)
		return(NULL);



}