/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:53:00 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 17:24:28 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	result = malloc(sizeof(char) * (src_len + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < src_len)
	{
		result[index] = src[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
