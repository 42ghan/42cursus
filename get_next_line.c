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

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	split_by_newline(t_lst *cur_fd, char **line, char *buf, int r_bytes)
{
	unsigned int	n_idx;
	char			*tmp;

	buf[r_bytes] = 0;
	tmp = cur_fd->backup;
	cur_fd->backup = ft_strjoin(cur_fd->backup, buf);
	free(tmp);
	if (cur_fd->backup == NULL)
		return (-1);
	n_idx = 0;
	while (cur_fd->backup[n_idx] && (cur_fd->backup[n_idx] != '\n'))
		n_idx++;
	if (n_idx == ft_strlen(cur_fd->backup))
		return (0);
	*line = ft_strndup(cur_fd->backup, n_idx);
	if (*line == 0)
		return (-1);
	tmp = cur_fd->backup;
	cur_fd->backup = ft_substr(cur_fd->backup, n_idx + 1,
	ft_strlen(cur_fd->backup) - n_idx - 1);
	free(tmp);
	if (cur_fd->backup == NULL)
		return (-1);
	return (1);
}

static void	clear_lst(t_lst **fd_lst, t_lst *cur_fd)
{
	t_lst	*prev;

	prev = *fd_lst;
	while (prev->next->fd != cur_fd->fd)
		prev = prev->next;
	prev->next = cur_fd->next;
	free(cur_fd->backup);
	free(cur_fd);
	cur_fd = NULL;
	if ((*fd_lst)->next == NULL)
	{
		free(*fd_lst);
		*fd_lst = NULL;
	}
}

static int	init_fd_lst(t_lst **fd_lst, t_lst **cur_fd, int fd)
{
	if (*fd_lst == NULL)
		*fd_lst = ft_lstnew(0, -2);
	if (*fd_lst == NULL)
		return (-1);
	(*cur_fd) = *fd_lst;
	while (*cur_fd)
	{
		if ((*cur_fd)->fd == fd)
			break ;
		*cur_fd = (*cur_fd)->next;
	}
	if (*cur_fd)
		return (1);
	*cur_fd = ft_lstnew(ft_strndup("", 1), fd);
	if (*cur_fd == NULL)
	{
		if ((*fd_lst)->next == NULL)
			free(fd_lst);
		return (-1);
	}
	ft_lstadd_back(fd_lst, *cur_fd);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_lst	*fd_lst;
	t_lst			*cur_fd;
	char			buf[BUFFER_SIZE + 1];
	int				read_bytes;
	int				split_res;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (!line) ||
	(init_fd_lst(&fd_lst, &cur_fd, fd) == -1))
		return (-1);
	while ((read_bytes = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		split_res = split_by_newline(cur_fd, line, buf, read_bytes);
		if (split_res == 1)
			return (1);
		else if (split_res == -1 || !read_bytes)
			break ;
	}
	if (!read_bytes)
		*line = ft_strndup(cur_fd->backup, ft_strlen(cur_fd->backup));
	clear_lst(&fd_lst, cur_fd);
	if (split_res == -1)
		return (-1);
	return (read_bytes);
}
