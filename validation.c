#include "validation.h"
#include "tetromino.h"
#include "tetr_list.h"
#include "find_solution.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		check_file(char* line)
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
    {
        write(1, "error\n", 6);
        exit(1);
    }
    return (1);
}

int		touch_validate(int touch)
{
    if (touch == 6 || touch == 8)
        return (1);
    else
    {
        write(1, "error\n", 6);
        exit(1);
    }
}

int		check_figure(char* line)
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

void	check_all(char* line, int rd)
{
    if ((rd < 21 && line[rd - 2] != '.' && line[rd - 2] != '#')
        || !check_file(line)
        || !check_figure(line))
    {
        write(1, "error\n", 6);
        exit(1);
    }
}

int		creation(int fd, int* figure_counter, t_tetr_list * *first_tetr_arr)
{
    t_tetromin* tetromin_head;
    t_tetr_list* current_tetr = 0;
    int			rd;
    char line[BUFF_SIZE + 1];

    while ((rd = read(fd, line, BUFF_SIZE)) > 0)
    {
        line[rd] = '\0';
        check_all(line, rd);
        if (*figure_counter == 0)
        {
            tetromin_head = cr_tet(line, *figure_counter);
            *first_tetr_arr = create_list(tetromin_head, NULL);
            current_tetr = *first_tetr_arr;
        }
        else
        {
            current_tetr->next = create_list(cr_tet(line, *figure_counter), NULL);
            current_tetr = current_tetr->next;
        }
        (*figure_counter)++;
    }
    if (line[20] != '\0')
        return 0;
    return (1);
}

int		setup(char** argv)
{
    int			fd;
    int			figure_counter;
    t_tetr_list* first_tetr_arr;

    figure_counter = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd <= -1)
        return (-1);
    if (!creation(fd, &figure_counter, &first_tetr_arr) || figure_counter > 26)
        return (0);
    find_solution(first_tetr_arr, figure_counter);
    return (1);
}

int		main(int argc, char** argv)
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