/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeogo <yeogo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:42:26 by yeogo             #+#    #+#             */
/*   Updated: 2022/04/28 06:59:11 by yeongo           ###   ########.fr       */
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	index;

	size = ft_tabsize(tab);
	while (size)
	{
		index = 1;
		while (index < size)
		{
			if (cmp(tab[index - 1], tab[index]) > 0)
				ft_swap(&tab[index - 1], &tab[index]);
			index++;
		}
		size--;
	}
}
