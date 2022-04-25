/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehokim <daehokim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:21:49 by daehokim          #+#    #+#             */
/*   Updated: 2022/04/23 21:52:17 by daehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "puzzle.h"

#include <stdio.h>

int count_word(char *str) 
{
	int	i;
	int word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			word_count++;
		i++;
	}
	word_count++;

	return word_count;
}

int *split_word(char *str, int word_count)
{
	int	*views;
	int	i;
	int word_idx;
	
	views = (int *)malloc(sizeof(int) * word_count);
	word_idx = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ') {
			views[word_idx] = str[i-1] - '0';
			word_idx++;
		}
		i++;
	}
	views[word_idx] = str[i-1] - '0';

	return views;
}

Board parse_board_info(char *str)
{
	Board board;
	int word_count;
	int	i;
	
	if (str == NULL || str[0] == '\0') {
		board.length = 0;
		return board;
	}
	word_count = count_word(str);
	if (word_count % 4 != 0) {
		board.length = 0;
		return board;
	}

	board.length = word_count / 4;
	board.views = split_word(str, word_count);
	board.cells = (int **)malloc(sizeof(int *) * board.length);
	board.is_end = 0;

	i = 0;
	while (i < board.length)
	{
		board.cells[i] = (int *)malloc(sizeof(int) * board.length);
		i++;
	}
	return board;
}


int	main(int argc, char **argv)
{
	Board board;
	
	board = parse_board_info(argv[1]);
	if (board.length == 0) {
		return argc; //TODO: temp
	}

	solve_puzzle(&board);	

	return argc; //TODO: temp
}
