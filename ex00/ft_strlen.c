/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikilisli <ikilisli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:53:54 by ikilisli          #+#    #+#             */
/*   Updated: 2024/08/12 16:13:46 by ikilisli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main (void)

// {
// 	char	*str = "123456";
// 	int	test;
// 	test = ft_strlen(str);
// 	char	w = '0' + test;
// 	write (1, &w, 1);
// }