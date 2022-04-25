/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:36 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 18:04:18 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_queens(int	*queens)
{
	int	col;
	int	temp;

	col = 0;
	while (col < 10)
	{
		temp = queens[col] + 48;
		write(1, &temp, 1);
		col++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-1 * nb);
	return (nb);
}

int	valid_check(int *queens, int col)
{
	int	index;

	index = 0;
	while (index < col)
	{
		if (queens[index] == queens[col] || \
				ft_abs(index - col) == ft_abs(queens[index] - queens[col]))
			return (0);
		index++;
	}
	return (1);
}

void	ft_set_queens(int *queens, int col, int *count)
{
	int	line;

	if (col == 10)
	{
		ft_print_queens(queens);
		*count += 1;
	}
	else
	{
		line = 0;
		while (line < 10)
		{
			queens[col] = line;
			if (valid_check(queens, col))
				ft_set_queens(queens, col + 1, count);
			line++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < 10)
	{
		queens[index] = 0;
		index++;
	}
	ft_set_queens(queens, 0, &count);
	return (count);
}
