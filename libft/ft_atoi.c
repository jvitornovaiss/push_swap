/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:09:57 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/28 18:07:59 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_overflow(long y, int digit)
{
	if (y > 214748364 || (y == 214748364 && digit > 7))
		ft_display_exit();
}

int	ft_atoi(const char *str)
{
	long	y;
	int		sign;

	y = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_display_exit();
	while (ft_isdigit(*str))
	{
		check_overflow(y, *str - '0');
		y = y * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		ft_display_exit();
	y *= sign;
	if (y > 2147483647 || y < -2147483648)
		ft_display_exit();
	return ((int)y);
}
