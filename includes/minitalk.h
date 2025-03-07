/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:42:46 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/07 21:49:02 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>

typedef struct s_msg
{
	int	len;
	long long	bits_read;
	int	len_bytes[32];
	int	*str;
	char	txt;
}	t_msg;

int *uint2binary(int n);
int binary2uint(int *bin);
int *char2binary(int n);
int binary2char(int *bin);
char *binary2str(int *bin, int len);

#endif