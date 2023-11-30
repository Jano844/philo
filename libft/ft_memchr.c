/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:54:29 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/26 21:57:16 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	let;

	i = 0;
	let = (char)c;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == let)
			return (str + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str1[] = "HelloWorld";
//     char str2[] = "HelloWorld";
//     int c = 'W';
//     size_t n = 6;
//     printf("%s\n", ft_memchr(str1, c, n));
//     printf("%s\n", memchr(str2, c, n));
//     return (0);
// }
