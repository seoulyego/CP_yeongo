/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:23:04 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 10:19:37 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_view	_view;
	t_board	_board;
	int		succeed;

	if (argc != 2)
		return (error_message());
	if (!initialize_struct(&_view, &_board, argv[1]))
		return (error_message());
	succeed = fill_board(&_view, &_board, 0, 0);
	free(_view.view);
	free_board(_board.board, _board.width);
	free(_board.board);
	if (!succeed)
		return (error_message());
	return (0);
}
