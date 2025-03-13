/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:56:17 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/13 08:00:45 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_ack;

void	ack_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_ack = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
		while (!g_ack)
			usleep(100);
		i--;
		c /= 2;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	char				*msg;

	if (argc != 3)
	{
		ft_printf("Please, provide all inputs\n");
		ft_printf("Valid format: %s PID Message\n", argv[0]);
		return (1);
	}
	sa.sa_sigaction = ack_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	send_char(pid, '\0');
}
