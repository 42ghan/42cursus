/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:17:29 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:29:17 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	ret = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ret + i);
		i++;
	}
	if (s[i] == (char)c)
		return (ret + i);
	return (0);
}
