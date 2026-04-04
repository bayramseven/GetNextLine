/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:12:09 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/04 02:49:02 by bayram-seve      ###   ########.fr       */
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

   /* buffer için malloc kadar yer aç
        read() ile açılan yeri doldur sonucu read_store a eşitle
        while döngüsüne girebilmesi için read_index 1 e eşile ki içeri giebilsin

        */
       
/*
    buffer size kadarını okuyup \n görene kadar statikdeğişkene ekle
    
    \n 'den öncesini sil ve \n den sonrasını statik değişkenin en başına koy
    ama silersen veri kaybolur. bunu swap şeklinde yapmalıyız muhtemelen. bunu iyicene araştır. ilk yapılacağı yap ondan sonra buna yoğunlaş.
*/


/*
nisan 19 toplantı  köy okul projesi müdürle      

*/