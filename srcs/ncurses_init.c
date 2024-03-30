#include "alcu.h"

static int set_cursed_values()
{
    if (curs_set(0) == ERR)
        return 1;
    raw();
    if (keypad(stdscr, TRUE) == ERR)
        return 1;
    if (nodelay(stdscr, TRUE) == ERR)
        return 1;
    if (!can_change_color() || !has_colors())
        return 1;
    if (start_color() == ERR)
        return 1;
    if (init_pair(1, COLOR_WHITE, COLOR_BLACK) == ERR)
        return 1;
    if (init_pair(2, 8, COLOR_BLACK) == ERR)
        return 1;
    if (init_pair(3, COLOR_WHITE, COLOR_GREEN) == ERR) // Selected Player
        return 1;
    if (init_pair(4, COLOR_WHITE, COLOR_RED) == ERR) // Selected Bot
        return 1;
    timeout(500);
    return 0;
}

int init_ncurses(WINDOW *stdscr)
{
    setlocale(LC_ALL, "");
    stdscr = initscr();
    if (!stdscr)
        return 1;
    if (set_cursed_values())
    {
        endwin();
        return 1;
    }
    return 0;
}