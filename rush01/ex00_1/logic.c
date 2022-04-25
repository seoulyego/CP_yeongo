/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehokim <daehokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:57:44 by daehokim          #+#    #+#             */
/*   Updated: 2022/04/23 21:52:18 by daehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "puzzle.h"

#include <stdio.h>

void permutation(Board *board, Permu *permu, int now_line, int is_end);
void fill_line(Board *board, Permu *permu, int now_line, int is_end);

int cal_view_backward(Board *board)
{
	int	i;
	int x;
	int y;
	int last;
	int view_make;

	i = 0;
	x = 0;
	while (x < board->length)
	{
		y = 0;
		view_make = 0;
		last = 0;
		while (y < board->length)
		{
			if (board->cells[y][x] > last)
			{
				view_make++;
				last = board->cells[y][x];
			}
			y++;
		}
		if (view_make != board->views[i])
			return 0;

		x++;
		i++;
	}

	x = 0;
	while (x < board->length)
	{
		y = board->length - 1;
		view_make = 0;
		last = 0;
		while (y >= 0)
		{
			if (board->cells[y][x] > last)
			{
				view_make++;
				last = board->cells[y][x];
			}
			y--;
		}
		if (view_make != board->views[i])
			return 0;
		x++;
		i++;
	}

	y = 0;
	while (y < board->length)
	{
		x = 0;
		view_make = 0;
		last = 0;
		while (x < board->length)
		{
			if (board->cells[y][x] > last)
			{
				view_make++;
				last = board->cells[y][x];
			}
			x++;
		}
		if (view_make != board->views[i])
			return 0;
		y++;
		i++;
	}

	y = 0;
	while (y < board->length)
	{
		x = board->length - 1;
		view_make = 0;
		last = 0;
		while (x >= 0)
		{
			if (board->cells[y][x] > last)
			{
				view_make++;
				last = board->cells[y][x];
			}
			x--;
		}
		if (view_make != board->views[i])
			return 0;
		y++;
		i++;
	}
	
	return 1;	
}

int fill_check(Board *board, int now_line)
{
	int	i;
	int	j;
	int is_same;

	i = 0;
	is_same = 0;
	while (i < now_line)
	{
		j = 0;
		while (j < board->length)
		{
			if (board->cells[now_line][j] == board->cells[i][j])
			{	
				is_same = 1;
				break;
			}
			j++;
		}
		if(is_same)
			break;
		i++;
	}
	
	if (is_same)
		return 0;
	return 1;	
}

void permutation(Board *board, Permu *permu, int now_line, int is_end)
{
	int	i;


	if (permu->col_depth == permu->r)
	{
		if (fill_check(board, now_line))
		{		
			Permu permu2;
			permu2.line_set = (int *)malloc(sizeof(int) * board->length);
			permu2.visit = (int *)malloc(sizeof(int) * board->length);
			permu2.pool = (int *)malloc(sizeof(int) * board->length);
			i = 0;
			while (i < board->length)
			{
				permu2.pool[i] = i+1;
				i++;
			}
			permu2.col_depth = 0;
			permu2.n = board->length;
			permu2.r = board->length;
		  	fill_line(board, &permu2, now_line + 1, is_end);
			return ;
		}
		else
			return ;
	}
	i = 0;
	while (i < permu->n)
	{
		if (!permu->visit[i])
		{
			permu->visit[i] = 1;
			board->cells[now_line][permu->col_depth] = permu->pool[i];
			permu->col_depth++;
			permutation(board, permu, now_line, is_end);
			if (board->is_end)
				break;
			permu->col_depth--;
			permu->visit[i] = 0;
		}
		i++;
	}
}

void fill_line(Board *board, Permu *permu, int now_line, int is_end)
{
	int	i;
	int	j;
	int print;

	if (now_line == board->length)
	{
		if (cal_view_backward(board))
		{
			for (i = 0; i < board->length; i++) {
				for (j = 0; j < board->length - 1; j++) {
					print = board->cells[i][j] + '0';
					write(1, &print, 1);
					write(1, " ", 1);
				}
				print = board->cells[i][j] + '0';
				write(1, &print, 1);
				write(1, "\n", 1);
			}

			board->is_end = 1;
			return ;
		}
		return ;
	}

	permutation(board, permu, now_line, is_end);	
}

int solve_puzzle(Board *board)
{
	int	i;

	Permu permu;
	permu.line_set = (int *)malloc(sizeof(int) * board->length);
	permu.visit = (int *)malloc(sizeof(int) * board->length);
	permu.pool = (int *)malloc(sizeof(int) * board->length);
	i = 0;
	while (i < board->length)
	{
		permu.pool[i] = i+1;
		i++;
	}
	permu.col_depth = 0;
	permu.n = board->length;
	permu.r = board->length;

	fill_line(board, &permu, 0, 0);	
	return 0;
}

