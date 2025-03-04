/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:20:06 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/04 21:48:06 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int *uint2binary(int n)
{
	int	*bin;
	int	i;

	bin = (int *)malloc(32);
	if (!bin)
		return (NULL);
	i = 31;
	while (i >= 0)
	{
		bin[i] = n % 2;
		n /= 2;
		i--;
	}
	return (bin);	
}

int binary2uint(int *bin)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i <= 31)
	{
		res = res * 2 + bin[i];
		i++;
	}
	return (res);
}
