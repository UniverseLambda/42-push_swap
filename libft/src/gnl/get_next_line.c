/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:13 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/25 13:49:14 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include <stdlib.h>

#include <ft_norm.h>
#include <ft_strbuff.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef struct s_static_buff
{
	char			content[BUFFER_SIZE];
	ssize_t			index;
	ssize_t			size;
	int				fd;
}					t_static_buff;

/*
** Reads the next unsigned char from fd. This method uses an internal static
** buffer to store the chars it reads from fd. The internal buffer size
** is BUFFER_SIZE.
**
** @return the next unsigned char from fd if any; -1 if it reaches the end of
** file of the fd; -2 if an error occured.
**
** @see man read(2)
** @see BUFFER_SIZE
*/

int	read_char(int fd)
{
	static t_static_buff	buffer = {.size = 0, .fd = -1};
	unsigned char			c;

	if (buffer.fd != fd)
	{
		buffer.size = 0;
		buffer.fd = fd;
	}
	if (buffer.index >= buffer.size)
	{
		buffer.index = 0;
		buffer.size = read(fd, buffer.content, BUFFER_SIZE);
		if (buffer.size == 0)
			return (-1);
		if (buffer.size == -1)
			return (-2);
	}
	c = (unsigned char)(buffer.content[buffer.index]);
	++(buffer.index);
	return ((int)c);
}

int	get_next_line(int fd, char **line)
{
	t_buff	*content;
	int		c;
	char	*result;

	if (BUFFER_SIZE == 0 || line == NULL)
		return (-1);
	content = create_buffer();
	if (content == NULL)
		return (-1);
	c = read_char(fd);
	while (c >= 0)
	{
		if (c == '\n' || !write_char_buffer(content, c))
		{
			if (c != '\n')
				c = -2;
			break ;
		}
		c = read_char(fd);
	}
	result = merge_buffer(content);
	c = ft_tern_i(result == NULL, -2, c);
	destroy_buffer(content);
	*line = result;
	return (ft_tern_i((c == -2) || (c == -1), c + 1, 1));
}
