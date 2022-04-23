/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:57:41 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/23 10:00:40 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	main(int ac, char **av)
{
	char	buffer[MAX_BUFF + 1];
	int		success;

	if (ac == 1)
	{
		error_message(NO_ARGS);
		return (1);
	}
	else if (ac > 2)
	{
		error_message(MANY_ARGS);
		return (1);
	}
	init_buffer(buffer);
	success = ft_display_file(av[1], buffer);
	if (!success)
	{
		error_message(FAIL_TO_READ);
		return (1);
	}
	return (0);
}
