/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:09:34 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 06:09:55 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int	main(int ac, char **av)
{
	char	**strs;

	strs = av + 1;
	if (ac > 1)
	{
		ft_sort_string_tab(strs);
		for (int i = 0; i < ac - 1; i++)
			printf("%s\n", strs[i]);
	}
	return (0);
}
