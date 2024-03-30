#include <unistd.h>
#include "alcu.h"

int bot_turn(int nb)
{
    if SHOULD_LOOSE(nb)
    {
        write(1, "try to loose\n", 13);
        if (N(nb) % 4 == 0)
            return (1);
        return ((N(nb)) % 4);
    }
    else
    {
        write(1, "try to win\n", 11);
        if (N(nb) % 4 == 1)
            return (1);
        return (N(nb) - 1 % 4);
    }
    return (0);
}
