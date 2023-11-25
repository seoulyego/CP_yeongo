/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:25:13 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 21:55:19 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

long long	ft_abs(long long number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ');
}

int	check_digits(int number, int base_size)
{
	if (number < base_size)
		return (1);
	return (1 + check_digits(number / 10, base_size));
}
