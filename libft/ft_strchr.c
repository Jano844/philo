/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:28 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/10 00:02:37 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while ((*str != '\0'))
	{
		if ((char)*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)*str == (char)c)
		return ((char *)str);
	return (NULL);
}

// int main()
// {
//     char str1[] = "HelloWorld";
//     char str2[] = "HelloWorld";
//     int letter = 'W';

//     printf("%s\n", ft_strchr(str1, letter));
//     //ft_strchr(str1, letter);
//     printf("%s\n", strchr(str2, letter));
//     return(0);
// }

// size_t	i;

// 	i = 0;
// 	while ((str[i] != '\0') && (str[i] != let))
// 	{
// 		i++;
// 	}
// 	if (str[i] == let)
// 	{
// 		return ((char *)str + i);
// 	}
// 	return (NULL);
