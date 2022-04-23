/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:31:35 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 22:13:13 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		src_len;
	int		index;

	src_len = ft_strlen(src);
	result =  malloc(sizeof(char) * (src_len + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index  < src_len)
	{
		result[index] = src[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			index;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		arr[index].size = ft_strlen(av[index]);
		arr[index].str = av[index];
		arr[index].copy = ft_strdup(av[index]);
		index++;
	}
	arr[index].str = 0;
	return (arr);
}
