/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:11:19 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 06:57:38 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*map_tab;

	if (length == 0)
		return (0);
	index = 0;
	map_tab = malloc(sizeof(int) * length);
	if (map_tab == NULL)
		return (0);
	while (index < length)
	{
		map_tab[index] = f(tab[index]);
		index++;
	}
	return (map_tab);
}
