/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:27:31 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 19:38:45 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_LIST_H
# define TETR_LIST_H

# include "tetromino.h"

typedef struct			s_tetr_list
{
	t_tetromin			*tetromin_data;
	struct s_tetr_list	*next;
}						t_tetr_list;

t_tetr_list				*create_list(t_tetromin *head, t_tetr_list *next);
void					lst_del(t_tetr_list **head);

#endif
