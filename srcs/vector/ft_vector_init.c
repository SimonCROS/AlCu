/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:50:49 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/30 11:34:34 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

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
