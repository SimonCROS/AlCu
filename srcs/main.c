#include <unistd.h>
#include "alcu.h"

void read_skip_line()
{
    char c;
    while (read(0, &c, 1) > 0 && c != '\n')
    {
    }
}

int atoi_from_read(int fd, int max)
{
    char c;
    int ret;
    int result = 0;
    while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            if (result == 0 && c == '0')
            {
                read_skip_line();
                return ERROR;
            }

            result = result * 10 + c - '0';
            if (result > max)
            {
                read_skip_line();
                return ERROR;
            }
        }
        else
        {
            read_skip_line();
            return ERROR;
        }
    }

    if (result == 0 && c == '\n')
    {
        return EMPTY;
    }
    if (ret == 0)
    {
        return END_OF_FILE;
    }
    return result;
}

#include <stdio.h> // TEST

int main(int argc, char **argv)
{
    int n;
    int total = 0;
    t_vector v;

    int map_fd;
    if (argc > 2)
    {
        ft_putstr_fd("ERROR\n", 2);
        return 1;
    }
    else if (argc == 2)
    {
        map_fd = open(argv[1], O_RDONLY);
        if (map_fd == -1)
        {
            ft_putstr_fd("ERROR\n", 2);
            return 1;
        }
    }
    else
    {
        map_fd = 0;
    }

    if (ft_vector_init(&v, (t_vinfos){sizeof(int), 0, NULL}))
    {
        write(2, "ERROR\n", 6);
        if (map_fd != 0)
        {
            close(map_fd);
        }
        return 1;
    }

    while ((n = atoi_from_read(map_fd, 10000)) > 0)
    {
        ft_putnbr(n);
        ft_putendl("");
        total += n;
        if (ft_vector_add(&v, &n))
        {
            write(2, "ERROR\n", 6);
            ft_vector_free(&v);
            if (map_fd != 0)
            {
                close(map_fd);
            }
            return 1;
        }
    }

    if (map_fd != 0)
    {
        close(map_fd);
    }

    if (n == ERROR)
    {
        ft_putstr_fd("ERROR\n", 2);
        ft_vector_free(&v);
        return 1;
    }

    ft_putstr("End of map\n");

    while (1)
    {
        ft_putstr("Please choose between 1 and 3 items\n");
        int choosen = atoi_from_read(0, 3);
        while (choosen == ERROR || choosen == EMPTY)
        {
            ft_putendl("Invalid choice");
            choosen = atoi_from_read(0, 3);
        }

        if (choosen == END_OF_FILE)
            break;
    }

    return 0;
}
