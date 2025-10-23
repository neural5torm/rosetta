/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:32:40 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/18 20:23:35 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copy_strlen.h"
#include "trim_space.h"
#include <stdlib.h>

char	*trim_space(char *str, long length)
{
	int	start;
	int	trimmed_length;

	start = 0;
	while (start < length && str[start] == ' ')
		start++;
	if (start == length)
		return (NULL);
	trimmed_length = 0;
	while (start + trimmed_length < length && str[start
			+ trimmed_length] != ' ')
		trimmed_length++;
	return (copy_strlen(str + start, trimmed_length));
}
