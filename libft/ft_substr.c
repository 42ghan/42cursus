/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:41:15 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:36:22 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	m_len;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	m_len = len;
	if ((ft_strlen(s) - start) <= len)
		m_len = ft_strlen(s) - start;
	ret = (char *)ft_calloc(m_len + 1, sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (s[start + i] && i < m_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
