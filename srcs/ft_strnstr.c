/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:29:46 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 19:29:49 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *h, const char *n, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	if (*n == 0)
		return (h);
	i = 0;
	while (*h && i < len)
	{
		if (*(h + i) == *n)
		{
			j = 1;
			while (*(h + i + j) && *(n + j) && *(h + i + j) == *(n + j))
				j++;
			if (*(n + j) == 0)
				return (h + i);
			else if (*(h + i + j) == 0)
				break ;
		}
		i++;
	}
	return (0);
}
