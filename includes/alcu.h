#ifndef ALCU_H

#include <unistd.h>
#include "ft_vector.h"
#include "ft_mem.h"

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
