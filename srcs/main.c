#include <unistd.h>
#include "ft_vector.h"
#include "ft_mem.h"

void read_skip_line()
{
    char c;
    while (read(0, &c, 1) > 0 && c != '\n')
    {
    }
}

int atoi_from_read()
{
    char c;
    int result = 0;
    while (read(0, &c, 1) > 0 && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            if (result == 0 && c == '0')
            {
                return -1;
            }

            result = result * 10 + c - '0';
            if (result > 10000)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    if (result == 0 && c == '\n')
    {
        return 0;
    }
    return result;
}

#include <stdio.h> // TEST

int main()
{
    int n;
    int total = 0;
    t_vector v;

    if (ft_vector_init(&v, (t_vinfos){sizeof(int), 0, NULL}))
    {
        write(2, "ERROR\n", 6);
        return 1;
    }

    while ((n = atoi_from_read()) > 0)
    {
        printf("%d\n", n);
        total += n;
        if (ft_vector_add(&v, &n))
        {
            write(2, "ERROR\n", 6);
            ft_vector_free(&v);
            return 1;
        }
    }

    if (n < 0)
    {
        write(2, "ERROR\n", 6);
        ft_vector_free(&v);
        read_skip_line();
        return 1;
    }

    for (size_t i = 0; i < v.total; i++)
    {
        printf("%d\n", *((int *)v.ptr + i));
    }
    printf("Total: %d\n", total);

    write(1, "End of map\n", 11);
    ft_vector_free(&v);
    return 0;
}
