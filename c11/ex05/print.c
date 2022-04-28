/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:12:06 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 02:25:31 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nbr)
{
	if (nbr == INT_MIN)
	{
		ft_putchar('-');
		ft_putnbr(nbr / 10 * -1);
		ft_putchar(nbr % 10 * -1 + '0');
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-1 * nbr);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
