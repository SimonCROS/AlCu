#include "alcu.h"

static int min(int a, int b)
{
    return a > b ? b : a;
}

static int max(int a, int b)
{
    return a < b ? b : a;
}

static void draw_map(t_vector *v, int to_take)
{
    clear();
    for (size_t i = 0; i < v->count; i++)
    {
        for (int j = 0; j < ft_vector_get(v, i); j++)
        {
            if (i == v->count - 1 && j < to_take)
            {
                attron(COLOR_PAIR(1));
                mvaddch(i, j, '|');
                attroff(COLOR_PAIR(1));
            }
            else
            {
                mvaddch(i, j, '|');
            }
        }
    }
    refresh();
}

int player_turn(t_vector *v, int count_on_line)
{
    int max_to_remove = min(3, count_on_line);
    int to_take = 1;
    while (1)
    {
        draw_map(v, to_take);

        printw("Please choose between 1 and %d items\n", max_to_remove);

        int ch = getch();
        if (ch == 27 || ch == 'q' || ch == 'Q')
        {
            return END_OF_FILE;
        }
        if (ch == KEY_UP)
        {
            to_take = min(to_take + 1, max_to_remove);
        }
        else if (ch == KEY_DOWN)
        {
            to_take = max(to_take - 1, 1);
        }
        else if (ch == KEY_ENTER || ch == KEY_RIGHT)
        {
            break;
        }
    }
    return to_take;
}
