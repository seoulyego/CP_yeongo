/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:46:31 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 17:46:36 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

void	ft_putnbr(int k)
{
	static char	buf[PUTNBR_BUFFER_SIZE];
	int			i;

	i = PUTNBR_BUFFER_SIZE - 1;
	buf[i--] = (k % 10) + '0';
	k /= 10;
	while (k)
	{
		buf[i--] = (k % 10) + '0';
		k /= 10;
	}
	i++;
	write(1, buf + i, PUTNBR_BUFFER_SIZE - i);
}

int	print_solution(t_skyscraper *sc)
{
	int	i;
	int	j;

	i = 0;
	while (i < sc->width)
	{
		j = 0;
		while (j < sc->width)
		{
			ft_putnbr(sc->board[i][j]);
			if (j + 1 != sc->width)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

void	fill_zeros(int *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		line[i] = 0;
		i++;
	}
}

int	ft_isnumber(char c)
{
	return ('0' <= c && c <= '9');
}

char	*ft_atoi(char *line, int *view)
{
	int	k;

	k = 0;
	while (ft_isnumber(*line))
	{
		k *= 10;
		k += *line - '0';
		line++;
	}
	*view = k;
	if (*line == ' ')
		line++;
	return (line);
}
