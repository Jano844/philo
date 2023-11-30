/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:29:07 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/26 20:32:35 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	if (!dest && !src)
		return (0);
	str1 = (char *)dest;
	str2 = (char *)src;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	dest = (char *)str1;
	return (dest);
}

// int main()
// {
// 	char src[] = "HelloWorld";
// 	char dest[100];
// 	int n = 10;

// 	printf("%s\n", ft_memcpy(dest, src, n));
// 	return(0);
// }
