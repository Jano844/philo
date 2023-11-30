/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:15:59 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/28 13:24:38 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0')
		return ((char *)hays);
	while (hays[i] != '\0' && i < len)
	{
		if (hays[i] == needle[0])
		{
			j = 0;
			while (hays[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)hays + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char hays[] = "Hallo Welten wo bist du";
//     char needle[] = "Welten";
//     size_t len = 15;

//     printf("%s\n", ft_strnstr(hays, needle, len));
//     printf("%s", strstr(hays, needle));
//     return(0);
// }
