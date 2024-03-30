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

void close_if_file(int fd)
{
    if (fd != 0)
    {
        close(fd);
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

int player_turn(int count_on_line)
{
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
        return END_OF_FILE;
    return choosen;
}

void print_strategy(t_vector *v) // REMOVE
{
	size_t	i;
	int		current;

	i = 0;
	while (i < v->total)
	{
		current = *(int *)ft_vector_get(v, i);
		ft_putnbr(current & 0x7FFFFFFF);
		if (current < 0)
			write(1, " | 1", 4);
		else
			write(1, " | 0", 4);
		write(1, "\n", 1);
		i++;
	}
    write(1, "\n", 1);
}

int game_loop(t_vector *v)
{
    int is_player_turn = 0;

    print_strategy(v);

    while (v->total > 0)
    {
        int *count_on_line_ptr = (int*)ft_vector_get(v, v->total - 1);

        int choosen;
        if (is_player_turn)
            choosen = player_turn(N(*count_on_line_ptr));
        else
            choosen = bot_turn(*count_on_line_ptr);

        if (choosen == END_OF_FILE)
            return END_OF_FILE;
        
        *count_on_line_ptr -= choosen;
        if (N(*count_on_line_ptr) == 0)
            v->total--;

        print_strategy(v);

        is_player_turn = !is_player_turn;
    }

    if (is_player_turn)
        ft_putendl("Player wins");
    else
        ft_putendl("AI wins");

    return EMPTY;
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
        if (ft_vector_add(v, &ret))
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

    if (argc > 2)
    {
        ft_putendl_fd("ERROR", 2);
        return 1;
    }

    if (ft_vector_init(&v, (t_vinfos){sizeof(int), 0, NULL}))
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

    if (v.total == 0)
    {
        ft_putendl_fd("ERROR", 2);
        ft_vector_free(&v);
        return 1;
    }

    find_strategy(&v);

    game_loop(&v);

    ft_vector_free(&v);
    return 0;
}
