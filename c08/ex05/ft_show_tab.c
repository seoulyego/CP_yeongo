/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:26:43 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 22:20:38 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		ft_putchar('\n');
		ft_putnbr(par[index].size);
		ft_putchar('\n');
		ft_putstr(par[index].copy);
		ft_putchar('\n');
		index++;
	}
}
