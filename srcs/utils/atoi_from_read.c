#include "alcu.h"

static void read_skip_line()
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
