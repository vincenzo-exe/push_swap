/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:00:59 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/11 13:00:59 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest < source)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dest[i] = source[i];
	}
	return (dst);
}
