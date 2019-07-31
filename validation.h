/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:07:39 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 19:12:09 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
# define BUFF_SIZE 21

# include "tetr_list.h"

int		check_file(char *line);
int		check_figure(char *line);
int		setup(char **argv);
void	creation(int fd, int *fig_counter, t_tetr_list **first_tetr_arr);
#endif
