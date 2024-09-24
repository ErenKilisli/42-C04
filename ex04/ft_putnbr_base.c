/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikilisli <ikilisli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:41:33 by ikilisli          #+#    #+#             */
/*   Updated: 2024/08/13 12:10:19 by ikilisli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	handle_putstr(unsigned int nb, int baselen, char *str, char *base)

{
	int	i;
	int	r;
	int	c;

	i = 0;
	r = 0;
	if (nb == 0)
		str[i++] = base[0];
	while (nb > 0)
	{
		str[i] = base[nb % baselen];
		nb = nb / baselen;
		i++;
	}
	str[i] = '\0';
	while (r < i / 2)
	{
		c = str[r];
		str[r] = str[i - 1 - r];
		str[i - 1 - r] = c;
		r++;
	}
	write (1, str, i);
}

int	handle_error(int baselen, char *base)

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (baselen < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)

{
	int				baselen;
	char			str[33];
	unsigned int	uni;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	if (handle_error(baselen, base) != 1)
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		uni = 2147483648;
		handle_putstr(uni, baselen, str, base);
		return ;
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		uni = nbr * -1;
	}
	else
		uni = nbr;
	handle_putstr(uni, baselen, str, base);
}
