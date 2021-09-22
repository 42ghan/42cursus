/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:13:09 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:40:04 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*new;

	head = ft_lstnew(NULL);
	if (!head)
		return (0);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, new);
		if (!new)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		lst = lst->next;
	}
	tmp = head;
	head = head->next;
	ft_lstdelone(tmp, del);
	return (head);
}
