/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:00:05 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 21:55:45 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

int			ft_strlen(char *str);
long long	ft_abs(long long number);
int			ft_isspace(char c);
int			check_digits(int number, int base_size);

int	base_valid_check(char *base)
{
	int	index;
	int	jndex;

	if (ft_strlen(base) < 2)
		return (0);
	index = 0;
	while (base[index])
	{
		if (ft_isspace(base[index]) || base[index] == '+' || base[index] == '-')
			return (0);
		jndex = index + 1;
		while (base[jndex])
		{
			if (base[index] == base[jndex])
				return (1);
			jndex++;
		}
		index++;
	}
	return (1);
}

int	convert_str(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_size;

	sign = 1;
	result = 0;
	base_size = ft_strlen(base);
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (convert_str(*str, base) != -1)
	{
		result *= base_size;
		result += sign * convert_str(*str, base);
		str++;
	}
	return (result);
}

void	ft_itoa_base(int number, char *result, int m_size, char *base)
{
	long long	abs_number;
	int			base_size;
	int			index;

	abs_number = ft_abs((long long)number);
	base_size = ft_strlen(base);
	index = m_size - 1;
	while (index >= 0)
	{
		result[index] = base[abs_number % base_size];
		abs_number /= base_size;
		index--;
	}
	if (number < 0)
		result[0] = '-';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	number;
	int			m_size;
	char		*result;
	int			index;

	if (!(base_valid_check(base_from) && base_valid_check(base_to)))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	if (number < INT_MIN || number > INT_MAX)
		return (NULL);
	m_size = check_digits(ft_abs(number), ft_strlen(base_to));
	if (number < 0)
		m_size += 1;
	result = malloc(sizeof(char) * (m_size + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < m_size + 1)
		result[index++] = '\0';
	ft_itoa_base(number, result, m_size, base_to);
	return (result);
}
