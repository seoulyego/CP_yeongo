/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:16:34 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 18:16:58 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_left_visible(t_skyscraper *sc, int y, int x, int num)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (sc->board[y][i] > num)
			return (VD_NONE);
		i++;
	}
	return (VD_LEFT);
}

int	is_right_visible(t_skyscraper *sc, int y, int x, int num)
{
	int	i;

	i = sc->width - 1;
	while (x < i)
	{
		if (sc->board[y][i] > num)
			return (VD_NONE);
		i--;
	}
	return (VD_RIGHT);
}

int	is_up_visible(t_skyscraper *sc, int y, int x, int num)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (sc->board[i][x] > num)
			return (VD_NONE);
		i++;
	}
	return (VD_UP);
}

int	is_down_visible(t_skyscraper *sc, int y, int x, int num)
{
	int	i;

	i = sc->width - 1;
	while (y < i)
	{
		if (sc->board[i][x] > num)
			return (VD_NONE);
		i--;
	}
	return (VD_DOWN);
}
