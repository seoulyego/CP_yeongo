/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:57:17 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/23 10:00:35 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	init_buffer(char *buffer)
{
	int	index;

	index = 0;
	while (index < MAX_BUFF + 1)
	{
		buffer[index] = '\0';
		index++;
	}
}
