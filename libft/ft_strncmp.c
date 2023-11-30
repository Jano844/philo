/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:50:37 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/28 13:24:33 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main()
// {
//     char str1[] = "HelloWorld";
//     char str2[] = "HelloWorld";
//     size_t size = 9;

//     printf("%i\n", ft_strncmp(str1, str2, size));
//     printf("%i\n", strncmp(str1, str2, size));
//     return(0);
// }
