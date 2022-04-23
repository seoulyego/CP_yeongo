/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:57:48 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/19 10:39:21 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

int	main(int argc, char **argv)
{
	int	index;
	int	size;

	size = argc - 1;
	while (size)
	{
		index = 1;
		while (index < size)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
				ft_swap(&argv[index], &argv[index + 1]);
			index++;
		}
		size--;
	}
	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		ft_putstr("\n");
		index++;
	}
	return (0);
}
