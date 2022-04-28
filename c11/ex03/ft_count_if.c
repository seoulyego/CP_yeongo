/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:11:30 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 06:57:53 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count;

	if (length == 0)
		return (0);
	index = 0;
	count = 0;
	while (index < length)
	{
		if (f(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}
