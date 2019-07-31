/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:05:07 by mflannel          #+#    #+#             */
/*   Updated: 2019/07/31 17:09:28 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "find_solution.h"
#include "tetr_list.h"
#include <fcntl.h>
#include <unistd.h>

int		setup(char **argv)
{
	int				fd;
	int				figure_counter;
	t_tetr_list		*first_tetr_arr;

	figure_counter = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= -1)
		return (-1);
	if (!creation(fd, &figure_counter, &first_tetr_arr) || figure_counter > 26)
		return (0);
	find_solution(first_tetr_arr, figure_counter);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!setup(argv))
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	else
		return (0);
	return (0);
}
