/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 03:12:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/21 05:03:28 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	find_index;

	if (!to_find[0])
		return (str);
	index = 0;
	while (str[index])
	{
		find_index = 0;
		while (str[index + find_index] && \
				str[index + find_index] == to_find[find_index])
		{
			if (!to_find[find_index + 1])
				return (&str[index]);
			find_index++;
		}
		index++;
	}
	return (0);
}
