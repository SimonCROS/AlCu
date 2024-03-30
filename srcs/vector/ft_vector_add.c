#include "ft_vector.h"

int	ft_vector_add(t_vector *v, void *item)
{
	if (!v)
		return (FAILURE);
	if (v->total == v->capacity)
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	ft_memcpy(v->ptr + v->total * v->size, item, v->size);
	v->total++;
	return (SUCCESS);
}
