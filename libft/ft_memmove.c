/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:14:27 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/26 20:41:25 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	if (!dest && !src)
		return (0);
	str1 = (char *)dest;
	str2 = (char *)src;
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
			str1[n] = str2[n];
	}
	else
	{
		while (i < n)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	dest = (char *)str1;
	return (dest);
}
