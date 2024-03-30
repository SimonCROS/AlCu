#include "alcu.h"

void close_if_file(int fd)
{
    if (fd != 0)
    {
        close(fd);
    }
}

int parse_map(char *path, t_vector *v)
{
    int ret;
    int map_fd = path == NULL ? 0 : open(path, O_RDONLY);

    if (map_fd == -1)
    {
        ft_putendl_fd("ERROR", 2);
        return ERROR;
    }

    while ((ret = atoi_from_read(map_fd, 10000)) > 0)
    {
        if (ft_vector_add(v, ret))
        {
            close_if_file(map_fd);
            return ERROR;
        }
    }

    close_if_file(map_fd);
    return ret;
}

int main(int argc, char **argv)
{
    t_vector v;
    WINDOW *win;

    if (argc > 2)
    {
        ft_putendl_fd("ERROR", 2);
        return 1;
    }

    if (ft_vector_init(&v, 0))
    {
        ft_putendl_fd("ERROR", 2);
        return 1;
    }

    if (parse_map(argc == 2 ? argv[1] : NULL, &v) == ERROR)
    {
        ft_vector_free(&v);
        ft_putendl_fd("ERROR", 2);
        return 1;
    }

    if (v.count == 0)
    {
        ft_putendl_fd("ERROR", 2);
        ft_vector_free(&v);
        return 1;
    }

    find_strategy(&v);

    win = NULL;
    if (init_ncurses(win))
    {
        ft_vector_free(&v);
        ft_putendl_fd("ERROR", 2);
        return 1;
    }

    game_loop(&v);

    endwin();
    ft_vector_free(&v);
    return 0;
}
