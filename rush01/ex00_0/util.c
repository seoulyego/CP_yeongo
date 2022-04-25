/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:18:56 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 10:19:32 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	parse_input(int *view, char *input_line)
{
	int	line_index;
	int	view_index;

	line_index = 0;
	view_index = 0;
	while (input_line[line_index])
	{
		view[view_index] = input_line[line_index] - '0';
		view_index++;
		line_index += 2;
	}
}

int	free_board(int **board, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		free(board[index]);
		index++;
	}
	return (1);
}

int	error_message(void)
{
	write(2, "Error\n", 6);
	return (1);
}
