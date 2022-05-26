/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:46:03 by yeongo            #+#    #+#             */
/*   Updated: 2022/05/26 15:28:50 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int	get_view_length(char *line)
{
	int	length;

	length = 0;
	while (*line)
	{
		while (ft_isnumber(*line))
			line++;
		length++;
		if (*line == ' ')
			line++;
		else if (*line == '\0')
			break ;
		else
			return (-1);
	}
	if (length == 0 || length % 4 != 0 || length > 36)
		return (-1);
	return (length);
}
