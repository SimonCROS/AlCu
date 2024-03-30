#include <unistd.h>
#include "alcu.h"

int	find_strategy(t_vector *v)
{
	size_t	i;
	int		*current;
	int		prev;

	prev = *(int *)ft_vector_get(v, 0);
	i = 1;
	while (i < v->total)
	{
		current = (int *)ft_vector_get(v, i);
		if (SHOULD_LOOSE(prev))
			SET_SHOULD_LOOSE_FLAG(*current, N(prev) % 4 != 1);
		else
			SET_SHOULD_LOOSE_FLAG(*current, N(prev) % 4 == 1);
		prev = *current;
		// prev = *current;
		i++;
	}
	return (0);
}

// int	find_strategy(t_vector *v)
// {
// 	size_t	i;
// 	int		*current;
// 	int		prev;

// 	prev = 0;
// 	i = 0;
// 	while (i < v->total)
// 	{
// 		current = (int *)ft_vector_get(v, i);
// 		if (i == 0)
// 			*current |= (*current % 4 != 1) << 31;
// 		else
// 		{
// 			if (prev)
// 				*current |= (*current % 4 != 1) << 31;
// 			else
// 				*current |= (*current % 4 == 1) << 31;
// 		}
// 		prev = *current < 0;
// 		i++;
// 	}
// 	print_strategy(v);
// 	return (0);
// }
