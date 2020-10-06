/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:03:33 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/16 09:52:10 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*list;
	t_list	*content_modifyed;

	if (!lst || !f)
		return (NULL);
	list = lst;
	newlist = NULL;
	while (list)
	{
		content_modifyed = f(list->content);
		if ((tmp = ft_lstnew(content_modifyed)) == NULL)
		{
			ft_lstclear(&newlist, del);
			free(content_modifyed);
			return (newlist);
		}
		ft_lstadd_back(&newlist, tmp);
		list = list->next;
	}
	return (newlist);
}
