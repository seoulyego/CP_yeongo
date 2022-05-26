/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:45:57 by yeongo            #+#    #+#             */
/*   Updated: 2022/05/26 15:19:42 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

void	fill_view_array(int *view, char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		line = ft_atoi(line, view + i);
		i++;
	}
}

int	**get_board(int width)
{
	int	**board;
	int	i;

	i = 0;
	board = malloc(sizeof(int *) * width);
	if (board == NULL)
		return (NULL);
	while (i < width)
	{
		board[i] = malloc(sizeof(int) * width);
		if (board[i] == NULL)
			return (clear_board(board, i));
		fill_zeros(board[i], width);
		i++;
	}
	return (board);
}

int	*get_view(char *line, int length)
{
	int	*view;

	view = malloc(sizeof(int) * length);
	if (view == NULL)
		return (NULL);
	fill_view_array(view, line);
	return (view);
}

int	fill_skyscrapper(t_skyscraper *sc, char *line)
{
	int	view_length;

	view_length = get_view_length(line);
	if (view_length == -1)
		return (1);
	sc->width = view_length / 4;
	sc->view._view = get_view(line, view_length);
	sc->view.up = sc->view._view;
	sc->view.down = sc->view._view + sc->width;
	sc->view.left = sc->view._view + sc->width * 2;
	sc->view.right = sc->view._view + sc->width * 3;
	sc->board = get_board(sc->width);
	if (sc->board == NULL)
	{
		free(sc->view._view);
		return (1);
	}
	return (0);
}

int	**clear_board(int **board, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (NULL);
}
