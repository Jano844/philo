/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:12:36 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/03 03:21:18 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str)
		return(NULL);
	while (str[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// int main()
// {
//     char *str1 = NULL;
//     char *str2 = ft_strdup(str1);

//     return(0);
// }
