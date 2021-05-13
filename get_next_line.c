/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:05:06 by ghan              #+#    #+#             */
/*   Updated: 2021/05/10 18:28:13 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	split_by_newline(char **backup, char **line, int fd)
{
	unsigned int	n_idx;
	char			*tmp;

	n_idx = 0;
	while (backup[fd][n_idx])
	{
		if (backup[fd][n_idx] == '\n')
			break ;
		n_idx++;
	}
	if (n_idx == ft_strlen(backup[fd]))
		return (0);
	*line = ft_strndup(backup[fd], n_idx);
	tmp = ft_substr(backup[fd], n_idx + 1, ft_strlen(backup[fd]) - n_idx - 1);
	if (!tmp)
		return (-1);
	backup[fd] = tmp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*backup[255];
	char		buf[BUFFER_SIZE + 1];
	int			read_bytes;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strndup("", 1);
	while ((read_bytes = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[read_bytes] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((ret = split_by_newline(backup, line, fd)) != 0)
			return (ret);
		if (!read_bytes)
		{
			*line = ft_strndup(backup[fd], ft_strlen(backup[fd]));
			free(backup[fd]);
			return (0);
		}
	}
	return (0);
}
