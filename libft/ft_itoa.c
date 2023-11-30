/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:30:22 by jsanger           #+#    #+#             */
/*   Updated: 2023/03/27 18:30:06 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static long int	get_digits(long int n)
{
	long int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = 0;
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	digits += get_digits(num);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (str_num == NULL)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

// int main()
// {
//     int n;
//     char *mall;

//     n = 0;
//     mall = ft_itoa(n);
//     printf("%s\n", mall);
//     free(mall);
//     return(0);
// }
