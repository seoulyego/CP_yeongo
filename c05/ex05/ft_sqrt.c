/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:16:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 12:12:23 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	index;

	if (nb < 0)
		return (0);
	index = 1;
	while (index * index <= (unsigned int) nb && index < 46341)
	{
		if (index * index == (unsigned int) nb)
			return (index);
		index++;
	}
	return (0);
}
