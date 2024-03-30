#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_free(t_vector *v)
{
	size_t	i;

	if (!v)
		return (FAILURE);
	if (v->del)
	{
		i = 0;
		while (i < v->total)
			v->del((void **)ft_vector_get(v, i++));
	}
	free(v->ptr);
	ft_memset(v, '\0', sizeof(t_vector));
	return (SUCCESS);
}
