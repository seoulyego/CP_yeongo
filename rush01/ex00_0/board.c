/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:17:41 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 10:18:48 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	fill_board(t_view *_view, t_board *_board, int y, int x)
{
	int	number;

	if (x == _board->width)
	{
		y += 1;
		x = 0;
	}
	if (y == _board->width)
		return (print_board(_board));
	number = 1;
	while (number <= _board->width)
	{
		_board->board[y][x] = number;
		if (check_board_valid(_view, _board, y, x)
			&& fill_board(_view, _board, y, x + 1))
			return (1);
		number++;
	}
	return (0);
}

int	print_board(t_board *_board)
{
	int		index;
	int		jndex;
	char	c;

	index = 0;
	while (index < _board->width)
	{
		jndex = 0;
		while (jndex < _board->width)
		{
			c = _board->board[index][jndex] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			jndex++;
		}
		write(1, "\n", 1);
		index++;
	}
	return (1);
}

int	check_board_valid(t_view *_view, t_board *_board, int y, int x)
{
	if (!check_unique(_board, y, x))
		return (0);
	if (x == _board->width - 1)
		if (!check_left_view(_view, _board, y, x)
			|| !check_right_view(_view, _board, y, x))
			return (0);
	if (y == _board->width - 1)
		if (!check_up_view(_view, _board, y, x)
			|| !check_down_view(_view, _board, y, x))
			return (0);
	return (1);
}
