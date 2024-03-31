#include "alcu.h"

int player_turn(t_vector *v, int count_on_line)
{
    const char *format = "Please choose between 1 and %d items";
    int center = COLS / 2;
    int line = LINES - 2;

    int max_to_remove = min(3, count_on_line);
    int to_take = 1;
    while (1)
    {
        clear();
        draw_map(v, to_take, 3);
        mvprintw(line, center - ft_strlen(format) / 2, format, max_to_remove);
        refresh();

        int ch = getch();
        if (ch == 27 || ch == 'q' || ch == 'Q')
        {
            return END_OF_FILE;
        }
        else if (ch == KEY_UP)
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
