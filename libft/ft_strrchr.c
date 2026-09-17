/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:01:00 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/11 13:01:00 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*match;

	i = 0;
	match = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			match = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (match);
}
