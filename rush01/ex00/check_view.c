/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:45:40 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 17:45:41 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	check_remain_space(int distance, int view_num)
{
	if (view_num == 1 && distance != 1)
		return (0);
	if (distance >= view_num)
		return (1);
	return (0);
}

int	check_up(t_skyscraper *sc, int y, int x, int num)
{
	if (!is_up_visible(sc, y, x, num))
		return (1);
	return (check_remain_space(y + 1, sc->view.up[x]));
}

int	check_down(t_skyscraper *sc, int y, int x, int num)
{
	if (!is_down_visible(sc, y, x, num))
		return (1);
	return (check_remain_space(sc->width - y, sc->view.down[x]));
}

int	check_left(t_skyscraper *sc, int y, int x, int num)
{
	if (!is_left_visible(sc, y, x, num))
		return (1);
	return (check_remain_space(x + 1, sc->view.left[y]));
}

int	check_right(t_skyscraper *sc, int y, int x, int num)
{
	if (!is_right_visible(sc, y, x, num))
		return (1);
	return (check_remain_space(sc->width - x, sc->view.right[y]));
}
