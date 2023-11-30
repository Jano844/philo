/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:18:14 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/28 13:24:07 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

// //Wenn dest kleiner ist als source muss
// //gebreakt werden und fehlermeldung ausgeschrieben werden
// int main()
// {
// 	char dest[4];
// 	char src[] = "Hello";

// 	char dest1[4];
// 	char src1[] = "Hello";

// 	unsigned int n = 9;

// 	printf("%zu\n", ft_strlcpy(dest, src, n));
// 	printf("%lu\n", strlcpy(dest1, src1, n));

// 	printf("%s\n", dest);
// 	printf("%s\n", dest1);
// 	return (0);
// }
