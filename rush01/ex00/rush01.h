/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:46:57 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 18:26:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define PUTNBR_BUFFER_SIZE 10
# define UNIQ_BUFFER_SIZE 100

typedef struct s_view
{
	int	*_view;
	int	*up;
	int	*down;
	int	*left;
	int	*right;
}	t_view;

typedef struct s_skyscraper
{
	t_view	view;
	int		**board;
	int		width;
}	t_skyscraper;

enum e_view_direction
{
	VD_NONE = 0,
	VD_UP = 1,
	VD_DOWN = 2,
	VD_LEFT = 4,
	VD_RIGHT = 8
};

char	*ft_atoi(char *line, int *view);
int		**clear_board(int **board, int last);
int		**get_board(int width);
int		*get_view(char *line, int length);
int		check_uniq(t_skyscraper *sc, int y, int x, int num);
int		check_up(t_skyscraper *sc, int y, int x, int num);
int		check_down(t_skyscraper *sc, int y, int x, int num);
int		check_left(t_skyscraper *sc, int y, int x, int num);
int		check_right(t_skyscraper *sc, int y, int x, int num);
int		end_with_error(void);
int		fill_board(t_skyscraper *sc, int num, int y);
int		fill_skyscrapper(t_skyscraper *sc, char *line);
int		ft_isnumber(char c);
int		get_view_length(char *line);
int		is_down_visible(t_skyscraper *sc, int y, int x, int num);
int		is_left_visible(t_skyscraper *sc, int y, int x, int num);
int		is_right_visible(t_skyscraper *sc, int y, int x, int num);
int		is_up_visible(t_skyscraper *sc, int y, int x, int num);
int		is_valid(t_skyscraper *sc, int y, int x, int num);
int		print_solution(t_skyscraper *sc);
void	fill_view_array(int *view, char *line);
void	fill_zeros(int *line, int width);
void	ft_putnbr(int k);

#endif
