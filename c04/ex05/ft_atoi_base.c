/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:01:37 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/21 04:57:43 by yeongo           ###   ########.fr       */
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

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int	base_valid_check(char *base)
{
	int	index;
	int	jndex;

	index = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[index])
	{
		if (ft_isspace(base[index]) || base[index] == '-' || base[index] == '+')
			return (0);
		jndex = index + 1;
		while (base[jndex])
		{
			if (base[index] == base[jndex])
				return (0);
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

	if (!base_valid_check(base))
		return (0);
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
