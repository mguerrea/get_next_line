/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:40:25 by mguerrea          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/25 15:53:21 by mguerrea         ###   ########.fr       */
=======
/*   Updated: 2018/11/10 16:59:28 by mguerrea         ###   ########.fr       */
>>>>>>> 0b7d525fd7c587b4264e94efaa56c17e88587a4d
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 32

int get_next_line(int fd, char **line);

#endif
