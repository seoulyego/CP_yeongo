/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:23:04 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/27 22:26:36 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int	func_num;

	if (argc != 4)
		return (1);
	func_num = argv_valid_check(argv[2], argv[3]);
	if (func_num == -1)
		return (1);
	do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), func_num);
	ft_putchar('\n');
	return (0);
}
