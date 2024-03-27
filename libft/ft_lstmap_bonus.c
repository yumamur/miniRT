/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:40:27 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 02:17:53 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&head, new);
		if (!new || !head)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
