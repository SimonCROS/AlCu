#ifndef ALCU_H

#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <wchar.h>
#include <locale.h>
#include "ft_vector.h"

#define SET_SHOULD_LOOSE_FLAG(num, condition) num |= (condition) << 31
#define SHOULD_LOOSE(num) ((num) & (1 << 31))
#define N(num) ((num) & ~(1 << 31))

#define EMPTY 0
#define ERROR -1
#define END_OF_FILE -2

int ft_strlen(const char *s);
int ft_putstr_fd(char *s, int fd);
int ft_putstr(char *s);
int ft_putnbr_fd(long n, int fd);
int ft_putnbr(long n);
int ft_putendl_fd(char *s, int fd);
int ft_putendl(char *s);
int ft_putchar_fd(char c, int fd);
int ft_putchar(char c);

int atoi_from_read(int fd, int max);

int find_strategy(t_vector *v);
int bot_turn(int v);
int player_turn(int count_on_line);

int init_ncurses(WINDOW *stdscr);
int game_loop(t_vector *v);

#endif