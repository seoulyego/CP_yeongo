/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeogo <yeogo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:31:07 by yeogo             #+#    #+#             */
/*   Updated: 2022/04/28 06:46:42 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tabsize(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
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
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	index;

	size = ft_tabsize(tab);
	while (size)
	{
		index = 1;
		while (index < size)
		{
			if (ft_strcmp(tab[index - 1], tab[index]) > 0)
				ft_swap(&tab[index - 1], &tab[index]);
			index++;
		}
		size--;
	}
}
