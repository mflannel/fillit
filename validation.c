/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:51:05 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 18:58:43 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "tetromino.h"
#include "tetr_list.h"
#include "find_solution.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"

int		check_file(char *line)
{
	int i;
	int hcount;
	int ncount;
	int dcount;

	i = 0;
	hcount = 0;
	ncount = 0;
	dcount = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			hcount++;
		else if (line[i] == '.')
			dcount++;
		else if (line[i] == '\n')
			ncount++;
		i++;
	}
	if (hcount != 4 || dcount != 12 || ncount > 5)
		error();
	return (1);
}

int		touch_validate(int touch)
{
	if (touch == 6 || touch == 8)
		return (1);
	else
	{
		error();
		return (0);
	}
}

int		check_figure(char *line)
{
	int touch;
	int hcount;
	int i;

	touch = 0;
	hcount = 0;
	i = 0;
	while (hcount < 4)
	{
		while (line[i] != '#')
			i++;
		if (line[i + 1] == '#')
			touch++;
		if (line[i - 1] == '#')
			touch++;
		if (line[i + 5] == '#')
			touch++;
		if (line[i - 5] == '#')
			touch++;
		hcount++;
		i++;
	}
	return (touch_validate(touch));
}

void	check_all(char *line, int rd)
{
	if ((rd < 21 && line[rd - 2] != '.' && line[rd - 2] != '#')
		|| !check_file(line)
		|| !check_figure(line))
	{
		error();
	}
}

int		creation(int fd, int *fig_counter, t_tetr_list **first_tetr_arr)
{
	t_tetromin		*tetromin_head;
	t_tetr_list		*current_tetr;
	int				rd;
	char			line[BUFF_SIZE + 1];

	while ((rd = read(fd, line, BUFF_SIZE)) > 0)
	{
		line[rd] = '\0';
		check_all(line, rd);
		if (*fig_counter == 0)
		{
			tetromin_head = cr_tet(line, *fig_counter);
			*first_tetr_arr = create_list(tetromin_head, NULL);
			current_tetr = *first_tetr_arr;
		}
		else
		{
			current_tetr->next = create_list(cr_tet(line, *fig_counter), NULL);
			current_tetr = current_tetr->next;
		}
		(*fig_counter)++;
		free(tetromin_head);
	}
	if (line[20] != '\0')
		return (0);
	return (1);
}
