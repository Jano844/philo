/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:08:39 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/27 20:43:52 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int let)
{
	char		*last;
	char		find;
	size_t		i;

	last = (char *)str;
	find = (char)let;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (0);
}

// int main()
// {
//     char str1[] = "HelloWorlWd";
//     char str2[] = "HelloWorlWd";
//     int letter = 'W';
//     printf("%s\n", ft_strrchr(str1, letter));
//     //ft_strchr(str1, letter);
//     printf("%s\n", strrchr(str2, letter));
//     return(0);
// }
