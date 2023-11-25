/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:00:23 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 21:11:31 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*result;
	unsigned int	size;
	unsigned int	index;

	if (min >= max)
		return (NULL);
	size = (unsigned int)(max - min);
	result = malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = min + index;
		index++;
	}
	return (result);
}
