/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_dealloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:59:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 19:38:58 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"

int	ft_vector_dealloc(t_vector **ptr, size_t n)
{
	size_t	i;

	if (!ptr || !*ptr || !n)
		return (FAILURE);
	i = 0;
	while (i < n)
		ft_vector_free((*ptr) + i++);
	free(*ptr);
	*ptr = NULL;
	return (SUCCESS);
}
