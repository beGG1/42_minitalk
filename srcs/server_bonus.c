/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:56:13 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/13 08:00:39 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>

static t_data	g_data;

void	init_global_variable(void)
{
	g_data.bit = 0;
	g_data.c = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_data.c |= (1 << (g_data.bit));
	kill(info->si_pid, SIGUSR1);
	g_data.bit++;
	if (g_data.bit == 8)
	{
		ft_printf("%c", g_data.c);
		if (g_data.c == '\0')
			ft_printf("\n");
		init_global_variable();
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
