/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:38:47 by mapryl            #+#    #+#             */
/*   Updated: 2019/07/31 18:19:43 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node_to_del;

	node_to_del = *alst;
	if (node_to_del == NULL)
		return ;
	del(node_to_del->content, node_to_del->content_size);
	free(node_to_del);
	*alst = NULL;
}
