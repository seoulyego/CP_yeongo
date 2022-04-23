/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:51:05 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/14 02:57:45 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n)
		index++;
	if (index == n)
		index--;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
