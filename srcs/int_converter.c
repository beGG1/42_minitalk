/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:20:06 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/07 22:06:21 by sshabali         ###   ########.fr       */
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

int *char2binary(int n)
{
	int	*bin;
	int	i;

	bin = (int *)malloc(8);
	ft_printf("jopa\n");
	if (!bin)
		return (NULL);
	i = 7;
	while (i >= 0)
	{
		bin[i] = n % 2;
		n /= 2;
		i--;
	}
	return (bin);	
}

int binary2char(int *bin)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i <= 7)
	{
		res = res * 2 + bin[i];
		i++;
	}
	return (res);
}

char *binary2str(int *bin, int len)
{
	int	i;
	int	j;
	char	*res;

	res = (char *)malloc((len / 8) + 1);
	i = 0;
	j = 0;
	ft_printf("%c\n", (char)binary2char(&bin[i]));
	while (i < len)
	{
		res[j] = (char)binary2char(&bin[i]);
		i = i + 8;
		j++;
	}
	res[j] = '\0';
	return (res);
}
