/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:25:10 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/25 18:03:37 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	index;

	if (nb < 2)
		return (0);
	else if (nb < 4)
		return (1);
	else if (nb % 2 == 0)
		return (0);
	index = 3;
	while (index < nb)
	{
		if (nb % index == 0)
			return (0);
		index += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
