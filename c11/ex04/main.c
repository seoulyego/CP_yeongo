/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:28:09 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/28 08:00:02 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_intcmp(int num1, int num2)
{
	return (num1 - num2);
}

int	main(void)
{
	int	tab1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	tab2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	tab3[10] = {8, 8, 7, 6, 4, 1, 3, 2, 1, 0};
	int	result1 = ft_is_sort(tab1, 10, &ft_intcmp);
	int	result2 = ft_is_sort(tab2, 10, &ft_intcmp);
	int	result3 = ft_is_sort(tab3, 10, &ft_intcmp);
	printf("result1 : 1 / %d\n", result1);
	printf("result2 : 1 / %d\n", result2);
	printf("result3 : 0 / %d\n", result3);
	return (0);
}
