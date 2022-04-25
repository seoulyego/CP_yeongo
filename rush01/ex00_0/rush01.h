/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:23:26 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 09:32:17 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_view
{
	int	*view;
	int	*view_up;
	int	*view_down;
	int	*view_left;
	int	*view_right;
}	t_view;

typedef struct s_board
{
	int	**board;
	int	width;
}	t_board;

int		get_view_length(char *input_line);
int		*make_view(char *input_line, int view_len);
void	parse_input(int *view, char *input_line);
int		**make_board(int width);
int		initialize_struct(t_view *_view, t_board *_board, char *input_line);
int		free_board(int **board, int n);
void	initialize_board(int *board_line, int width);
int		fill_board(t_view *_view, t_board *_board, int y, int x);
int		print_board(t_board *_board);
int		check_unique(t_board *_board, int y, int x);
int		check_board_valid(t_view *_view, t_board *_board, int y, int x);
int		check_left_view(t_view *_view, t_board *board, int y, int x);
int		check_right_view(t_view *_view, t_board *board, int y, int x);
int		check_up_view(t_view *_view, t_board *board, int y, int x);
int		check_down_view(t_view *_view, t_board *board, int y, int x);
int		error_message(void);

#endif
