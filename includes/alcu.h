#ifndef ALCU_H

#include <unistd.h>
#include <fcntl.h>
#include "ft_vector.h"
#include "ft_mem.h"

#define SET_SHOULD_WIN_FLAG(num, condition) num |= (condition) << 31
#define SHOULD_WIN(num) ((num) & (1 << 31))
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

#endif