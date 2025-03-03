/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:44:57 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/04 21:59:30 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>

void	handler_sig1(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Got SIGUSR1\n");
}

void	handler_sig2(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Got SIGUSR2\n");
}

int	main()
{
	int	a;

	a = getpid();
	ft_printf("Server PID: %i\n", a);
	signal(SIGUSR1, handler_sig1);
	signal(SIGUSR2, handler_sig2);
	sigaddset(sigset_t *set, int signo)
	while(1)
		pause();
	
	return (0);
}
