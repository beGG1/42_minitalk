/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:09:28 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/04 10:25:44 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *next)
{
	t_list	*l;

	if (!lst || !(*lst))
	{
		*lst = next;
		return ;
	}
	l = *lst;
	while (l->next)
		l = l->next;
	l->next = next;
}
