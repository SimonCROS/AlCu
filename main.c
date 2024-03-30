#include <unistd.h>

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
    while ((n = atoi_from_read()) > 0)
    {
        printf("%d\n", n);
    }

    if (n < 0)
    {
        write(2, "ERROR\n", 6);
        read_skip_line();
        return 1;
    }

    write(1, "End of map\n", 11);
    return 0;
}
