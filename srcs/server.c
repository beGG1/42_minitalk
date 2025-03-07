/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:44:57 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/07 22:00:40 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_msg	g_msg;

void	init_msg(void)
{
	g_msg.bits_read = 0;
	g_msg.len = 0;
	g_msg.str = NULL;
	g_msg.txt = 0;
}

void	handler_sig(int sig)
{
	int	n;
	char	*str;

	if (sig == SIGUSR1)
		n = 1;
	if (sig == SIGUSR2)
		n = 0;
	if (g_msg.bits_read < 32 && !g_msg.txt)
	{
		g_msg.len_bytes[g_msg.bits_read] = n;
		g_msg.bits_read++;
	}
	if (g_msg.bits_read == 32 && !g_msg.txt)
	{
		g_msg.len = binary2uint(g_msg.len_bytes);
		g_msg.str = (int *)malloc(8 * g_msg.len);
		g_msg.txt = 1;
		return ;
	}
	if (g_msg.txt)
	{
		ft_printf("jopa\n");
		g_msg.str[g_msg.bits_read - 32] = n;
		g_msg.bits_read++;
	}	
	if (g_msg.bits_read - 1 >= (g_msg.len * 8 + 32))
	{
		str = binary2str(g_msg.str, g_msg.len);
		ft_printf("%s\n", str);
		free(str);
		free(g_msg.str);
		init_msg();
	}
}

int	main()
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	init_msg();
	signal(SIGUSR1, handler_sig);
	signal(SIGUSR2, handler_sig);
	while(1)
		pause();
	
	return (0);
}
