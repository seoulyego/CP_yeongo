/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:53:08 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/16 12:00:57 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int cur_column, int cur_line, int end_column, int end_line)
{
	if (cur_line == 0 || cur_line == end_line)
	{
		if (cur_column == 0)
			ft_putchar('A');
		else if (cur_column == end_column)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (cur_column == 0 || cur_column == end_column)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	end_column;
	int	end_line;
	int	cur_column;
	int	cur_line;

	if (x <= 0 || y <= 0)
		return ;
	end_column = x - 1;
	end_line = y - 1;
	cur_line = 0;
	while (cur_line < y)
	{
		cur_column = 0;
		while (cur_column < x)
		{
			print_line(cur_column, cur_line, end_column, end_line);
			cur_column++;
		}
		ft_putchar('\n');
		cur_line++;
	}
}
