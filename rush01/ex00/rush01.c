/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:46:10 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/24 18:28:09 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

int	end_with_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_skyscraper	sc;
	int				success;

	if (argc != 2)
		return (end_with_error());
	if (fill_skyscrapper(&sc, argv[1]))
		return (end_with_error());
	success = fill_board(&sc, sc.width, 0);
	free(sc.view._view);
	clear_board(sc.board, sc.width);
	if (!success)
		return (end_with_error());
	return (0);
}
