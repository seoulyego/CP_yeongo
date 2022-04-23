/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:56:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/23 10:00:46 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
