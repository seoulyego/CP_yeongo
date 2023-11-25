/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:06:17 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 18:00:34 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				*result;
	unsigned int	size;
	unsigned int	index;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = (unsigned int)(max - min);
	result = malloc(sizeof(int) * size);
	if (!result)
		return (-1);
	index = 0;
	while (index < size)
	{
		result[index] = min + index;
		index++;
	}
	*range = result;
	return (size);
}
