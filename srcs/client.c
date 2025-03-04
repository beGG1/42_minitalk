/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:09:54 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/04 21:57:22 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

int	send_text(int pid, char *text)
{
	int	str_len;
	int	*bin;
	int	i;

	str_len = (int)ft_strlen(text);
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
	return (str_len);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2 || argc > 4)
		return (1);
	
	pid = ft_atoi(argv[1]);
	send_text(pid, argv[2]);
}