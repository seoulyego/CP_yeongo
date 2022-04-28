/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:12:01 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 02:09:47 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	argv_valid_check(char *op, char *nbr)
{
	int	func_num;

	func_num = in_char(op[0], "+-*/%");
	if (!(ft_strlen(op) == 1 && func_num != -1))
	{
		ft_putstr("0\n");
		return (-1);
	}
	if (func_num == 3 && ft_atoi(nbr) == 0)
	{
		ft_putstr(DIV_ERR_MSG);
		return (-1);
	}
	else if (func_num == 4 && ft_atoi(nbr) == 0)
	{
		ft_putstr(MOD_ERR_MSG);
		return (-1);
	}
	return (func_num);
}

void	do_op(int num1, int num2, int func_num)
{
	t_calc	f_calc[5];
	int		result;

	f_calc[0] = add;
	f_calc[1] = sub;
	f_calc[2] = mul;
	f_calc[3] = div;
	f_calc[4] = mod;
	result = f_calc[func_num](num1, num2);
	ft_putnbr(result);
}
