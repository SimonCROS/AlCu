#include <unistd.h>
#include "alcu.h"

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

    if (c == '0')
    {
        return -2;
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
        ft_putstr_fd("ERROR\n", 2);
        ft_vector_free(&v);
        read_skip_line();
        return 1;
    }

    ft_putstr("End of map\n");

    int choosen;
    do
    {
        ft_putstr("Please choose between 1 and 3 items\n");
        choosen = atoi_from_read();

        // TEST
        ft_putstr("You choose\n");
        ft_putnbr(n);
        ft_putendl("");
    } while ((choosen >= 1 && choosen <= 3) || choosen == -2);
    
    return 0;
}
