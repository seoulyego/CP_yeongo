/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:34:02 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/23 10:00:19 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	ft_display_file(char *path, char *buff)
{
	ssize_t	fd;
	ssize_t	read_size;

	fd = open(path, O_RDONLY);
	if (fd == (ssize_t) -1)
		return (0);
	read_size = 0;
	while (read_size != (ssize_t) -1)
	{
		read_size = read(0, buff, MAX_BUFF);
		if (read_size == (ssize_t) -1)
			return (1);
		ft_putstr(buff);
		init_buffer(buff);
		if (read_size == 0)
			break ;
	}
	close(fd);
	return (1);
}
