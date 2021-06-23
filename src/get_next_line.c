/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:46:01 by ghan              #+#    #+#             */
/*   Updated: 2021/05/17 16:30:55 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	split_by_nl(char **backup, char **line, char *buf, int r_bytes)
{
	unsigned int	n_idx;
	char			*tmp;

	buf[r_bytes] = 0;
	tmp = *backup;
	*backup = ft_strjoin(*backup, buf);
	free(tmp);
	if (*backup == NULL)
		return (-1);
	n_idx = 0;
	while (*(*backup + n_idx) && (*(*backup + n_idx) != '\n'))
		n_idx++;
	if (n_idx == ft_strlen(*backup))
		return (0);
	*line = ft_strndup(*backup, n_idx);
	if (*line == 0)
		return (-1);
	tmp = *backup;
	*backup = ft_substr(*backup, n_idx + 1, ft_strlen(*backup) - n_idx - 1);
	free(tmp);
	if (*backup == NULL)
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[1025];
	int			read_bytes;
	int			split_res;

	if (!backup)
		backup = ft_strndup("", 1);
	if ((!line) || !backup)
		return (-1);
	while ((read_bytes = read(fd, buf, 1024)) >= 0)
	{
		split_res = split_by_nl(&backup, line, buf, read_bytes);
		if (split_res == 1)
			return (1);
		else if (split_res == -1 || !read_bytes)
			break ;
	}
	if (!read_bytes)
		*line = ft_strndup(backup, ft_strlen(backup));
	free(backup);
	if (split_res == -1)
		return (-1);
	return (read_bytes);
}
