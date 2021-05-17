/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:32:25 by ghan              #+#    #+#             */
/*   Updated: 2021/05/14 17:20:09 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char			*ft_strndup(const char *s1, size_t n)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (s1[len])
		len++;
	if (len > n)
		len = n;
	if (!(ret = (char*)malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static t_list	*find_fd_elem(t_list *fd_list, int fd)
{
	t_list *cur;

	cur = fd_list;
	while (cur)
	{
		if (cur->fd == fd)
			break ;
		cur = cur->next;
	}
	return (cur);
}

static int		split_by_newline(t_list *cur_fd, char **line, char *buf)
{
	unsigned int	n_idx;
	char			*tmp;

	tmp = cur_fd->backup;
	if (!(cur_fd->backup = ft_strjoin(cur_fd->backup, buf)))
		return (-1);
	free(tmp);
	n_idx = 0;
	while (cur_fd->backup[n_idx] && (cur_fd->backup[n_idx] != '\n'))
		n_idx++;
	if (n_idx == ft_strlen(cur_fd->backup))
		return (0);
	*line = ft_strndup(cur_fd->backup, n_idx);
	tmp = cur_fd->backup;
	cur_fd->backup = ft_substr(cur_fd->backup, n_idx + 1,
			ft_strlen(cur_fd->backup) - n_idx - 1);
	free(tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*cur_fd;
	char			buf[BUFFER_SIZE + 1];
	int				read_bytes;
	int				ret;

	cur_fd = 0;
	if ((fd < 0) || (fd > 256) || (BUFFER_SIZE <= 0) || (!line))
		return (-1);
	if (!fd_list)
		fd_list = ft_lstnew(0, -2);
	if (!(cur_fd = find_fd_elem(fd_list, fd)))
	{
		if (!(cur_fd = ft_lstnew(ft_strndup("", 1), fd)))
		{
			free(fd_list);
			return (-1);
		}
		ft_lstadd_back(&fd_list, cur_fd);
	}
	while ((read_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytes] = 0;
		if ((ret = split_by_newline(cur_fd, line, buf)) != 0)
		{
			if (ret == -1)
			{
				free(cur_fd);
				free(fd_list);
			}
			return (ret);
		}
	}
	*line = ft_strndup(cur_fd->backup, ft_strlen(cur_fd->backup));
	ft_lstdelone(cur_fd, &fd_list, free);
	free(fd_list);
	fd_list = NULL;
	return (0);
}
