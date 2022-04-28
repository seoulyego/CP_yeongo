/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:11:57 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/27 22:26:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int num1, int num2)
{
	return (num1 + num2);
}

int	sub(int num1, int num2)
{
	return (num1 - num2);
}

int	mul(int num1, int num2)
{
	if (num1 == 0 || num2 == 0)
		return (0);
	if (num1 != 0 && num2 == 1)
		return (num1);
	else if (num1 == 1 && num2 != 0)
		return (num2);
	return (num1 * num2);
}

int	div(int num1, int num2)
{
	return (num1 / num2);
}

int	mod(int num1, int num2)
{
	return (num1 % num2);
}
