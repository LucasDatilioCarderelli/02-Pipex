/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:42:50 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/17 19:57:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	tot_size;

	tot_size = nmemb * size;
	dst = malloc(tot_size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, tot_size);
	return (dst);
}
