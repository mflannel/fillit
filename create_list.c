/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:36:36 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 19:36:30 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr_list.h"
#include <stdlib.h>
#include "error.h"

t_tetr_list		*create_list(t_tetromin *head, struct s_tetr_list *next)
{
	struct s_tetr_list *tmp;

	tmp = (t_tetr_list*)malloc(sizeof(t_tetr_list));
	if (!tmp)
		error();
	tmp->tetromin_data = head;
	tmp->next = next;
	return (tmp);
}

void			lst_delone(t_tetr_list **head)
{
	t_tetr_list	*node_to_del;

	node_to_del = *head;
	if (node_to_del == NULL)
		return ;
	free(node_to_del->tetromin_data->form);
	free(node_to_del->tetromin_data);
	free(node_to_del);
	head = NULL;
}

void			lst_del(t_tetr_list **head)
{
	t_tetr_list *node_to_del;
	t_tetr_list *next;

	node_to_del = *head;
	while (node_to_del != NULL)
	{
		next = node_to_del->next;
		lst_delone(&node_to_del);
		node_to_del = next;
	}
	*head = NULL;
}
