/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:46:02 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 17:16:12 by yeongo           ###   ########.fr       */
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

int	check_size(int size, char **strs, char *sep)
{
	int	index;
	int	length;
	int	sep_len;

	index = 0;
	length = 0;
	sep_len = ft_strlen(sep);
	while (index < size)
	{
		length += ft_strlen(strs[index]);
		if (index < size - 1)
			length += sep_len;
		index++;
	}
	return (length);
}

void	offset_cpy(char *dest, char *src, int *dest_offset)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[*dest_offset + index] = src[index];
		index++;
	}
	dest[*dest_offset + index] = '\0';
	*dest_offset += index;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		index;
	int		offset;

	if (!size)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (check_size(size, strs, sep) + 1));
	if (!result)
		return (NULL);
	index = 0;
	offset = 0;
	while (index < size)
	{
		offset_cpy(result, strs[index], &offset);
		if (index != size - 1)
			offset_cpy(result, sep, &offset);
		index++;
	}
	return (result);
}
