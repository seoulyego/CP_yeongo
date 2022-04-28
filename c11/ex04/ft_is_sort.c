/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:11:36 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 06:58:34 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ascending_order(int *tab, int length, int (*f)(int, int))
{
	int	index;

	index = 1;
	while (index < length)
	{
		if (f(tab[index - 1], tab[index]) > 0)
			return (0);
		index++;
	}
	return (1);
}

int	is_descending_order(int *tab, int length, int (*f)(int, int))
{
	int	index;

	index = 1;
	while (index < length)
	{
		if (f(tab[index - 1], tab[index]) < 0)
			return (0);
		index++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;

	if (length == 0)
		return (1);
	index = 1;
	while (index < length)
	{
		if (f(tab[index - 1], tab[index]) < 0)
			return (is_ascending_order(tab, length, f));
		else if (f(tab[index - 1], tab[index]) > 0)
			return (is_descending_order(tab, length, f));
		else
			index++;
	}
	return (1);
}
