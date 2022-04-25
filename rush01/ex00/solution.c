/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:45:25 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 17:45:26 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	add_number(t_skyscraper *sc, int y, int x, int num)
{
	int	modified_dirs;

	sc->board[y][x] = num;
	modified_dirs = 0;
	modified_dirs |= is_up_visible(sc, y, x, num);
	if (modified_dirs & VD_UP)
		sc->view.up[x] -= 1;
	modified_dirs |= is_down_visible(sc, y, x, num);
	if (modified_dirs & VD_DOWN)
		sc->view.down[x] -= 1;
	modified_dirs |= is_left_visible(sc, y, x, num);
	if (modified_dirs & VD_LEFT)
		sc->view.left[y] -= 1;
	modified_dirs |= is_right_visible(sc, y, x, num);
	if (modified_dirs & VD_RIGHT)
		sc->view.right[y] -= 1;
	return (modified_dirs);
}

void	remove_number(t_skyscraper *sc, int remove_dir, int y, int x)
{
	sc->board[y][x] = 0;
	if (remove_dir & VD_UP)
		sc->view.up[x] += 1;
	if (remove_dir & VD_DOWN)
		sc->view.down[x] += 1;
	if (remove_dir & VD_LEFT)
		sc->view.left[y] += 1;
	if (remove_dir & VD_RIGHT)
		sc->view.right[y] += 1;
}

int	fill_board(t_skyscraper *sc, int num, int y)
{
	int	x;
	int	modified_dirs;

	if (num == 0)
		return (print_solution(sc));
	if (y == sc->width)
		return (fill_board(sc, num - 1, 0));
	x = 0;
	while (x < sc->width)
	{
		if (is_valid(sc, y, x, num))
		{
			modified_dirs = add_number(sc, y, x, num);
			if (fill_board(sc, num, y + 1))
				return (1);
			remove_number(sc, modified_dirs, y, x);
		}
		x++;
	}
	return (0);
}
