/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:25:47 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 14:20:16 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/trim_space.h"
#include "parse_line.h"
#include "parse_number.h"
#include <stdlib.h>

#define KEY_SEP ':'

int	empty_status(long key_length)
{
	if (key_length == 0)
		return (0);
	return (-1);
}

int	invalid_status(char *key, char *value)
{
	if (key && value)
		return (1);
	return (-1);
}

int	parse_line(char *line, char **key, char **value)
{
	long	key_length;
	long	value_length;

	*key = NULL;
	*value = NULL;
	if (line == NULL)
		return (0);
	key_length = 0;
	while (line[key_length] && line[key_length] != KEY_SEP)
		key_length++;
	if (!line[key_length])
		return (empty_status(key_length));
	value_length = 0;
	while (line[key_length + value_length])
		value_length++;
	*key = parse_number(line, key_length);
	*value = trim_space(line + key_length + 1, value_length);
	return (invalid_status(*key, *value));
}
