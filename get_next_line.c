/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:28:34 by mguerrea          #+#    #+#             */
/*   Updated: 2018/09/23 19:43:51 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#include <stdio.h>

#define BUFF_SIZE 4

void    ft_lstaddback(t_list **list, t_list *new)
{
    t_list *temp;

    temp = *list;
    if (!temp)
    {
        *list = new;
        return ;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

int ft_checkline(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *ft_cpy_line(char *dst, char *src, char *perm)
{
    size_t i;
    size_t len;

    i = 0;
    while (src[i] != '\n' && src[i])
        i++;
//    printf("b6\n");
    len = i;
    if (perm)
        len = i + ft_strlen(perm);
    dst = ft_strnew(len);
//    printf("b7\n");
    if (perm)
        dst = ft_strcpy(dst, perm);
//    printf("b8\n");
    dst = ft_strncat(dst, src, i);
    return (dst);
}

char *ft_save(char *str)
{
    int i;
    char *temp;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    i++;
    temp = ft_strdup(&str[i]);
    return (temp);
}

int get_next_line(int fd, char **line)
{
    int ret;
    char buf[BUFF_SIZE + 1];
    t_list *list;
    t_list *new;
    static char *perm = NULL;
    char *str;

    list = NULL;
//    printf("b1\n");
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
//        printf("b2\n");
        new = ft_lstnew(buf, ret + 1);
//        printf("b3\n");
        ft_lstaddback(&list, new);
//        printf("b4\n");
        if (ft_checkline(buf))
            break ;
    }
    ft_list_to_str(list, &str);
//    printf("b5\n");
    *line = ft_cpy_line(*line, str, perm);
    perm = ft_save(str);
    return (0);
}

int main(int argc, char **argv)
{
    char *line;
    int fd;
    int i;

    fd = open(argv[1], O_RDONLY);
    i = get_next_line(fd, &line);
    ft_putstr(line);
    ft_putchar('\n');
    i = get_next_line(fd, &line);
    ft_putstr(line);
    ft_putchar('\n');
    return(0);
}