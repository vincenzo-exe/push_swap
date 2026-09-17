/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:05:28 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/11 13:05:28 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_list = NULL;
	while (temp != NULL)
	{
		content = f(temp->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (content != NULL)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		temp = temp->next;
	}
	return (new_list);
}
