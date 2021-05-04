/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:47:48 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 17:47:49 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	void			*ret;

	ret = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)ret == (unsigned char)c)
			return (ret);
		ret++;
		i++;
	}
	return (0);
}
