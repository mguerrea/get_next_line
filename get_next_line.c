/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:28:34 by mguerrea          #+#    #+#             */
/*   Updated: 2018/09/26 15:12:27 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int ft_checkline(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *ft_save(char *str, char *perm)
{
    int i;
    char *temp;

    i = 0;
    if (ft_checkline(perm))
    {
        while(perm[i] != '\n')
            i++;
        i++;
        temp = ft_strnew(ft_strlen(&perm[i]) + ft_strlen(str));
        temp = ft_strcpy(temp, &perm[i]);
        temp = ft_strcat(temp, str);
        return (temp);
    }
    while (str[i + 1] && str[i] != '\n')
        i++;
    i++;
    temp = ft_strdup(&str[i]);
    return (temp);
}

char    *ft_cpy_line(char *dst, char *src, char **perm)
{
    size_t i;
    size_t len;

    i = 0;
    if (ft_checkline(*perm))
    {
        while ((*perm)[i] != '\n')
            i++;
        dst = ft_strnew(i);
        dst = ft_strncpy(dst, *perm, i);
        *perm = ft_save(src, *perm);
        return (dst);
    }
    while (src[i] != '\n' && src[i])
        i++;
    len = i;
    if (*perm)
        len = i + ft_strlen(*perm);
    dst = ft_strnew(len);
    if (*perm)
        dst = ft_strcpy(dst, *perm);
    dst = ft_strncat(dst, src, i);
    *perm = ft_save(src, *perm);
    return (dst);
}

int get_next_line(int fd, char **line)
{
    int ret;
    char buf[BUFF_SIZE + 1];
    t_list *list;
    static char *perm = NULL;
    char *str;

    list = NULL;
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        if (ret == -1)
            return (-1);
        buf[ret] = '\0';
        ft_lstaddback(&list, ft_lstnew(buf, ret + 1));
        if (ft_checkline(buf))
            break ;
    }
    if (!list && !perm[0])
        return(0);
 //   printf("quoi\n");
    str = ft_list_to_str(list);
 //   printf("oui ?\n");
    *line = ft_cpy_line(*line, str, &perm);
    ft_strdel(&str);
    return (1);
}