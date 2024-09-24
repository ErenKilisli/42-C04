/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikilisli <ikilisli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:21:57 by ikilisli          #+#    #+#             */
/*   Updated: 2024/08/12 16:34:05 by ikilisli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)

{
	int		i;
	int		mcount;
	int		r;

	r = 0;
	i = 0;
	mcount = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mcount++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	if (mcount % 2 == 0)
		return (r);
	else
		return (-r);
}

// int	main(int ac, char **av)

// {
// 	ft_atoi(*av);
// 	return 0;
// }