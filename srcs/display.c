#include "alcu.h"

#ifdef NCURSES
    void draw_map_ncurses(t_vector *v, int to_take, int to_take_color)
    {
        int center_x = COLS / 2;

        for (size_t i = 0; i < v->count; i++)
        {
            int length = N(ft_vector_get(v, i));
            for (int j = 0; j < length; j++)
            {
                int col = center_x - length + (j * 2);
                int row = LINES - 3 - (v->count - i);
                int overflow = (length * 2) - COLS;
                int is_last_line = i == v->count - 1;
                int row_color_type = min(max(max(3 - (v->count - i - 1), 0), row), 3);
                int color_pair_index = 1;
                int dimmed = 0;
                char c = '|';

                if (row < 0)
                {
                    continue;
                }
                if (overflow > 0)
                {
                    col = COLS - (length - j) * 2;
                }
                if (col < 0)
                {
                    continue;
                }
                if (overflow > 0)
                {
                    mvprintw(row, 0, " %+d ", overflow);
                }

                if (row_color_type == 0)
                {
                    color_pair_index = 2;
                    dimmed = 1;
                }
                if (row_color_type == 1)
                {
                    color_pair_index = 2;
                }
                if (row_color_type == 2)
                {
                    dimmed = 1;
                }
                if (row_color_type == 3 && is_last_line && j >= length - to_take)
                {
                    color_pair_index = to_take_color;
                }

                attron(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
                mvaddch(row, col, c);
                attroff(COLOR_PAIR(color_pair_index) | (A_DIM * dimmed));
            }
        }
    }
#else
    void draw_map_term(t_vector *v, int to_take, int to_take_color)
    {
        size_t i = 0;

        (void)to_take;
        (void)to_take_color;
        write(1, "\n", 1);
        while (i < v->count)
        {
            int line = N(ft_vector_get(v, i));
            for (int j = 0; j < line; j++)
            {
                write(1, "|", 1);
            }
            i++;
            write(1, "\n", 1);
        }
        write(1, "\n", 1);
        // if (to_take_color == 3)
        // {
        //     ft_putstr("\nPlease choose between 1 and ");
        //     ft_putnbr(to_take);
        //     ft_putstr(" items\n");
        // }
        // else
        // {
        //     ft_putstr("\nThe Bot take ");
        //     ft_putnbr(to_take);
        //     ft_putstr(" items\n");
        // }
    }
#endif

void    draw_map(t_vector *v, int to_take, int to_take_color)
{
    #ifdef NCURSES
        draw_map_ncurses(v, to_take, to_take_color);
    #else
        draw_map_term(v, to_take, to_take_color);
    #endif
}
