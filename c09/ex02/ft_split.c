/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:25:19 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/22 22:02:05 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_issep(char c, char *sep)
{
	int	index;

	index = 0;
	while (sep[index])
	{
		if (c == sep[index])
			return (1);
		index++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_res_size(char *str, char *charset)
{
	int	count;
	int	index;

	count = 0;
	index = 1;
	while (str[index - 1] && str[index])
	{
		if (!ft_issep(str[index - 1], charset) && ft_issep(str[index], charset))
			count++;;
		index++;
	}
	if (ft_issep(str[index], charset))
		count++;
	return (count);
}

int	ft_res_alloc(char **result, char *str, char *sep, int m_size)
{
	int	length;
	int	index;
	int	x;

	x = 0;
	while (x < m_size)
	{
		length = 0;
		index = 0;
		while (str[index] && ft_issep(str[index], sep))
			index++;
		while (str[index] && !ft_issep(str[index], sep))
		{
			length++;
			index++;
		}
		result[x] = malloc(sizeof(char) * (length + 1));
		if (!result[x])
			return (0);
		x++;
	}
	return (1);
}

void	ft_rescpy(char **result, char *str, char *sep, int m_size)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	while (x < m_size)
	{
		y = 0;
		while (str[index] && ft_issep(str[index], sep))
			index++;
		while (str[index] && !ft_issep(str[index], sep))
		{
			result[x][y] = str[index];
			index++;
			y++;
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
	result = malloc(sizeof(char *) * (m_size + 1));
	if (!result)
		return (NULL);
	if (!ft_res_alloc(result, str, charset, m_size))
		return (NULL);
	ft_rescpy(result, str, charset, m_size);
	return (result);
}
