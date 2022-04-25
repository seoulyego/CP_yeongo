/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehokim <daehokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:58:58 by daehokim          #+#    #+#             */
/*   Updated: 2022/04/23 21:16:38 by daehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_H
#define PUZZLE_H

typedef struct _Board
{
	int *views;
	int length;
	int **cells;
	int is_end;
} Board;

typedef struct _Permu
{
	int *line_set;
	int *visit;
	int *pool;
	int col_depth;
	int n;
	int r;
} Permu;

int solve_puzzle(Board *board);

#endif
