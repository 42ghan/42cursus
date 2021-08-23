/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:59:35 by ghan              #+#    #+#             */
/*   Updated: 2021/05/04 15:59:36 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char digit;

	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n / 10 > 0)
		{
			digit = n % 10 + '0';
			n /= 10;
			ft_putnbr_fd(n, fd);
		}
		else
			digit = '0' + n;
		write(fd, &digit, 1);
	}
	return ;
}
