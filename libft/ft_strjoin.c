/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:00:59 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/11 13:00:59 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr_join;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr_join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!arr_join)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		arr_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		arr_join[len_s1 + i] = s2[i];
		i++;
	}
	arr_join[len_s1 + len_s2] = '\0';
	return (arr_join);
}
