/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:08:06 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/27 16:08:25 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_issep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_res_size(char *str, char *charset)
{
	int	index;
	int	count;

	index = 1;
	count = 0;
	while (str[index - 1] && str[index])
	{
		if (!ft_issep(str[index - 1], charset) && ft_issep(str[index], charset))
			count++;
		index++;
	}
	if (str[index - 1] && !ft_issep(str[index - 1], charset))
		count++;
	return (count);
}

int	ft_res_alloc(char **result, int size, char *str, char *charset)
{
	int	x;
	int	index;
	int	length;

	x = 0;
	index = 0;
	while (str[index] && x < size)
	{
		length = 0;
		while (str[index] && ft_issep(str[index], charset))
			index++;
		while (str[index] && !ft_issep(str[index], charset))
		{
			index++;
			length++;
		}
		result[x] = malloc(sizeof(char) * (length + 1));
		if (result[x] == NULL)
			return (0);
		x++;
	}
	return (1);
}

void	ft_res_copy(char **result, int size, char *str, char *charset)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	x = 0;
	while (str[index] && x < size)
	{
		y = 0;
		while (str[index] && ft_issep(str[index], charset))
			index++;
		while (str[index] && !ft_issep(str[index], charset))
		{
			result[x][y] = str[index];
			y++;
			index++;
		}
		result[x][y] = '\0';
		x++;
	}
	result[x] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		m_size;
	char	**result;

	m_size = ft_res_size(str, charset);
	result = (char **)malloc(sizeof(char *) * (m_size + 1));
	if (result == NULL)
		return (NULL);
	if (!ft_res_alloc(result, m_size, str, charset))
		return (NULL);
	ft_res_copy(result, m_size, str, charset);
	return (result);
}
