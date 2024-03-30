#include <unistd.h>
#include "alcu.h"

int bot_turn(int nb)
{
	if (SHOULD_LOOSE(nb))
	{
		if (N(nb) % 4 == 0)
			return (1);
		return ((N(nb)) % 4);
	}
	else
	{
		if (N(nb) % 4 == 1)
			return (1);
		return (N(nb) - 1 % 4);
	}
	return (0);
}

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
