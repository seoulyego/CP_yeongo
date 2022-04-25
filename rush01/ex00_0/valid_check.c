/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:16:18 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 10:17:26 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_unique(t_board *_board, int y, int x)
{
	int	index;

	index = 0;
	while (index < x)
	{
		if (_board->board[y][index] == _board->board[y][x])
			return (0);
		index++;
	}
	index = 0;
	while (index < y)
	{
		if (_board->board[index][x] == _board->board[y][x])
			return (0);
		index++;
	}
	return (1);
}

int	check_left_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	height;
	int	index;

	max = 0;
	height = 0;
	index = 0;
	while (index <= x)
	{
		if (max < _board->board[y][index])
		{
			max = _board->board[y][index];
			height++;
		}
		index++;
	}
	if (height != *(_view->view_left + y))
		return (0);
	return (1);
}

int	check_right_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = x;
	while (index >= 0)
	{
		if (max < _board->board[y][index])
		{
			max = _board->board[y][index];
			height++;
		}
		index--;
	}
	if (height != *(_view->view_right + y))
		return (0);
	return (1);
}

int	check_up_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = 0;
	while (index <= y)
	{
		if (max < _board->board[index][x])
		{
			max = _board->board[index][x];
			height++;
		}
		index++;
	}
	if (height != *(_view->view_up + x))
		return (0);
	return (1);
}

int	check_down_view(t_view *_view, t_board *_board, int y, int x)
{
	int	max;
	int	index;
	int	height;

	max = 0;
	height = 0;
	index = y;
	while (index >= 0)
	{
		if (max < _board->board[index][x])
		{
			max = _board->board[index][x];
			height++;
		}
		index--;
	}
	if (height != *(_view->view_down + x))
		return (0);
	return (1);
}
