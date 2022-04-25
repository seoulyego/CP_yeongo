/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:45:32 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 17:45:43 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_uniq(t_skyscraper *sc, int y, int x, int num)
{
	int	i;

	i = 0;
	while (i < sc->width)
	{
		if (sc->board[i][x] == num)
			return (0);
		if (sc->board[y][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(t_skyscraper *sc, int y, int x, int num)
{
	if (sc->board[y][x])
		return (0);
	if (!check_uniq(sc, y, x, num))
		return (0);
	return (
		check_up(sc, y, x, num)
		&& check_down(sc, y, x, num)
		&& check_left(sc, y, x, num)
		&& check_right(sc, y, x, num)
	);
}
