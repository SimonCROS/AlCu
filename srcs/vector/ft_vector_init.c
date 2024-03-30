#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_init(t_vector *v, t_vinfos infos)
{
	if (!v || infos.data_size < 1)
		return (FAILURE);
	if (infos.capacity < 1)
		v->capacity = VECTOR_INIT_CAPACITY;
	else
		v->capacity = infos.capacity;
	v->total = 0;
	v->size = infos.data_size;
	v->del = infos.del;
	v->ptr = malloc(v->size * v->capacity);
	if (!v->ptr)
	{
		ft_memset(v, '\0', sizeof(t_vector));
		return (FAILURE);
	}
	ft_memset(v->ptr, 0, v->size);
	return (SUCCESS);
}
