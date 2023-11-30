/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:39 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/29 12:55:30 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(1 * (len1 + len2 + 1));
	if (str == 0)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
	{
		str[len1] = s1[len1];
		len1++;
	}
	while (s2[len2] != '\0')
	{
		str[len1] = s2[len2];
		len1++;
		len2++;
	}
	str[len1] = '\0';
	return (str);
}

// int	main ()
// {
// 	char	str1[] = "Alle meine Entchen ";
// 	char	str2[] = "schwimmen auf dem See.";
// 	char	*str = ft_strjoin(str1, str2);
// 	printf("%s\n", str);
// 	free(str);
// 	return(0);
// }
