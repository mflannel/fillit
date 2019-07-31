/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:36:36 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 17:37:58 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr_list.h"
#include <stdlib.h>
#include <error.h>

t_tetr_list		*create_list(t_tetromin *head, struct s_tetr_list *next)
{
	struct s_tetr_list *tmp;

	tmp = (t_tetr_list*)malloc(sizeof(t_tetr_list));
	if (!tmp)
		error();
	tmp->tetromin_data = *head;
	tmp->next = next;
	return (tmp);
}
