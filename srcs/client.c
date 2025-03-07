/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:09:54 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/07 22:05:30 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

int	send_len(int pid, int str_len)
{
	int	*bin;
	int	i;

	bin = uint2binary(str_len);
	i = 0;
	while (i <= 31)
	{
		usleep(700);
		if (bin[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
	free(bin);
	return (str_len);
}

int	send_text(int pid, char *text)
{
	int	*bin;
	int	i;

	while (*text)
	{
		bin = char2binary((int)*text);
		i = 0;
		while (i <= 7)
		{
			usleep(700);
			if (bin[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
		}
		free(bin);
		text++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2 || argc > 4)
		return (1);
	
	pid = ft_atoi(argv[1]);
	if (argc == 2)
		send_len(pid, 0);
	else
	{
		send_len(pid, (int)ft_strlen(argv[2]));
		send_text(pid, argv[2]);
	}
}