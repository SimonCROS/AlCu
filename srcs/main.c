#include <unistd.h>
#include "alcu.h"

void read_skip_line()
{
    char c;
    while (read(0, &c, 1) > 0 && c != '\n')
    {
    }
}

int min(int a, int b)
{
    return a > b ? b : a;
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
        ft_putendl_fd("ERROR", 2);
        return 1;
    }
    else if (argc == 2)
    {
        map_fd = open(argv[1], O_RDONLY);
        if (map_fd == -1)
        {
            ft_putendl_fd("ERROR", 2);
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
        ft_putendl_fd("ERROR", 2);
        ft_vector_free(&v);
        return 1;
    }

    while (v.total > 0)
    {
        int *count_on_line_ptr = (int*)ft_vector_get(&v, v.total - 1);
        int count_on_line = *count_on_line_ptr;

        int max_to_remove = min(3, count_on_line);
        ft_putstr("Please choose between 1 and ");
        ft_putnbr(max_to_remove);
        ft_putendl(" items");
        int choosen = atoi_from_read(0, min(3, max_to_remove));
        while (choosen == ERROR || choosen == EMPTY)
        {
            ft_putendl("Invalid choice");
            choosen = atoi_from_read(0, 3);
        }

        if (choosen == END_OF_FILE)
            break;
        
        *count_on_line_ptr -= choosen;
        if (*count_on_line_ptr == 0)
        {
            v.total--;
        }
    }

    ft_vector_free(&v);
    return 0;
}
