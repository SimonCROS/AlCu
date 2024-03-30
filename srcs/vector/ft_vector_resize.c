#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_resize(t_vector *v, size_t capacity)
{
	void	*new;

	if (!v || capacity < v->total || !capacity)
		return (FAILURE);
	new = malloc(v->size * capacity);
	if (!new)
		return (FAILURE);
	ft_memcpy(new, v->ptr, v->size * v->total);
	free(v->ptr);
	v->ptr = new;
	v->capacity = capacity;
	return (SUCCESS);
}
