/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:25:45 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/21 17:45:40 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	base_valid_check(char *base)
{
	int	index;
	int	jndex;

	index = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[index])
	{
		if (base[index] == '-' || base[index] == '+')
			return (0);
		jndex = index + 1;
		while (base[jndex])
		{
			if (base[index] == base[jndex])
				return (0);
			jndex++;
		}
		index++;
	}
	return (1);
}

void	convert_base(int nbr, int base_size, char *base)
{
	if (nbr >= base_size)
		convert_base(nbr / base_size, base_size, base);
	ft_putchar(base[nbr % base_size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	if (!base_valid_check(base))
		return ;
	base_size = ft_strlen(base);
	if (nbr == INT_MIN)
	{
		ft_putchar('-');
		convert_base(nbr / base_size * -1, base_size, base);
		ft_putchar(base[nbr % base_size * -1]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		convert_base(nbr * -1, base_size, base);
	}
	else
		convert_base(nbr, base_size, base);
}
