/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikilisli <ikilisli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:20:42 by ikilisli          #+#    #+#             */
/*   Updated: 2024/08/14 13:03:11 by ikilisli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reverse(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int	convert_to_string(unsigned int nb, char *str)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (i);
	}
	while (nb > 0)
	{
		str[i++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	str[i] = '\0';
	reverse(str, i);
	return (i);
}

void	ft_putnbr(int nb)
{
	char			str[12];
	int				len;
	unsigned int	n;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}
	else
		n = nb;
	len = convert_to_string(n, str);
	write(1, str, len);
}
