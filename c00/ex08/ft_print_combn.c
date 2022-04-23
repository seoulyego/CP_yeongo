/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:41:32 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/14 01:06:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	ft_print_numbers(int n, int combn[9])
{
	int	index;

	index = 0;
	while (index < n)
	{
		ft_putnbr(combn[index]);
		index++;
	}
	if (combn[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_set_combn(int n, int combn[9], int index, int start_num)
{
	if (index == n)
		ft_print_numbers(n, combn);
	else
	{
		while (start_num < 10 - ((n - 1) - index))
		{
			combn[index] = start_num;
			ft_set_combn(n, combn, index + 1, start_num + 1);
			start_num++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	combn[9];
	int	index;

	index = 0;
	while (index < 10)
	{
		combn[index] = index;
		index++;
	}
	ft_set_combn(n, combn, 0, 0);
}
