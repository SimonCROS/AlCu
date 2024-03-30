#ifndef ALCU_H

#include <unistd.h>
#include <fcntl.h>
#include "ft_vector.h"
#include "ft_mem.h"

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
