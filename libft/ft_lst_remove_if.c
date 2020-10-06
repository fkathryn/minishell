/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:28:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/04 16:49:04 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **begin_list,
					void *data_ref, int (*cmp)())
{
	t_list	*element;
	t_list	*temp;

	element = *begin_list;
	while (element && element->next)
	{
		if ((*cmp)(element->next->content, data_ref) == 0)
		{
			temp = element->next;
			element->next = element->next->next;
			free(temp);
		}
		else
			element = element->next;
	}
	element = *begin_list;
	if (element && (*cmp)(element->content, data_ref) == 0)
	{
		*begin_list = element->next;
		free(element);
	}
}
