#include <unistd.h>
#include "alcu.h"

int find_strategy(t_vector *v)
{
    size_t    i;
    int     current;
    int     prev;

    prev = ft_vector_get(v, 0);
    i = 1;
    while (i < v->count)
    {
        current = ft_vector_get(v, i);
        if (SHOULD_LOOSE(prev))
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 != 1);
        else
            SET_SHOULD_LOOSE_FLAG(current, N(prev) % 4 == 1);
        prev = current;
        i++;
    }
    return (0);
}
