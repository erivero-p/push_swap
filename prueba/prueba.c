/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:02:25 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 11:07:40 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>

int	chunk_size(int	*numbers)
{
	int	max;
	int	len;
	int min;
	int size;

	max = numbers[0];
	min = max;
	len = 4;
	while (len-- > 0)
	{
		if (max < numbers[len])
			max = numbers[len];
		if (min > numbers[len])
			min = numbers[len];
	}
	size = max - min + 1;
	printf("max: %i\n", max);
	printf("min: %i\n", min);
	printf("size: %i\n", size);
	return (size);
}
int	main (void)
{
	int numbers[] = {-20, 4, 8, 20};
	chunk_size(numbers);
}