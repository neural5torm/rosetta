/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:40:34 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/18 17:26:53 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_file_size.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

long	get_file_size(int fd)
{
	ssize_t	n_bytes;
	ssize_t	total_size;
	char	*buffer[BUFFER_SIZE];

	total_size = 0;
	n_bytes = BUFFER_SIZE;
	while (n_bytes == BUFFER_SIZE)
	{
		n_bytes = read(fd, &buffer, BUFFER_SIZE);
		if (n_bytes)
			total_size += n_bytes;
	}
	return (total_size);
}
