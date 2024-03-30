/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:14:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/30 11:30:34 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	void	*ret;
	size_t	i;

	ret = s;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
	return (ret);
}
