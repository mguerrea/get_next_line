/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:30:15 by mguerrea          #+#    #+#             */
/*   Updated: 2018/09/23 18:09:50 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void    ft_list_to_str(t_list *list, char **str)
{
    size_t size;
    t_list *temp;

    temp = list;
    size = 0;
    while (temp)
    {
        size = size + temp->content_size - 1;
        temp = temp->next;
    }
    *str = ft_strnew(size);
    temp = list;
    while (temp)
    {
        *str = ft_strcat(*str, temp->content);
        temp = temp->next;
    }
}