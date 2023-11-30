/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:25:51 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/28 13:24:14 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*s;
	size_t	len_dest;
	size_t	res;
	size_t	len_src;
	size_t	i;

	s = (char *)src;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > len_dest)
		res = len_src + len_dest;
	else
		res = len_src + size;
	while (s[i] && (len_dest + 1) < size)
	{
		dest[len_dest] = s[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (res);
}
// int main()
// {
// 	char dest[] = "Hello-";
// 	char src[] = "World";

// 	char dest1[] = "Hello-";
// 	char src1[] = "World";

// 	unsigned int n = 3;

// 	printf("%zu\n", ft_strlcat(dest, src, n));
// 	printf("%lu\n", strlcat(dest1, src1, n));

// 	printf("%s\n", dest);
// 	printf("%s\n", dest1);
// 	return (0);
// }

// size_t	ft_strlcat(char *dest, char *src, size_t size)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = 0;
// 	while (dest[i] != '\0')
// 	{
// 		i++;
// 	}
// 	while (src[j] != '\0' && j < size - 1)
// 	{
// 		dest[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	return (i);
// }
