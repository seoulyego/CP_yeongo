/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:11:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 02:25:41 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <limits.h>
# include <unistd.h>

# define DIV_ERR_MSG "Stop : division by zero\n"
# define MOD_ERR_MSG "Stop : modulo by zero\n"

typedef int	(*t_calc)(int value1, int value2);

int		in_char(char c, char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		add(int num1, int num2);
int		sub(int num1, int num2);
int		mul(int num1, int num2);
int		div(int num1, int num2);
int		mod(int num1, int num2);
int		argv_valid_check(char *op, char *nbr);
void	do_op(int value1, int value2, int func_num);

#endif
