/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:23:54 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/06 13:01:10 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	n_p;

	i = 0;
	num = 0;
	n_p = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			n_p = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (n_p * num);
}

// int main()
// {
//     char charNumber1[] = "-100";
//     char charNumber2[] = "-100";
//     int number1 = ft_atoi(charNumber1);
//     int number2 = atoi(charNumber2);
//     int sum = number1 + number2;
//     printf("%i + %i  = %i\n", number1, number2, sum);
//     return(0);
// }
