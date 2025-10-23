/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:56:40 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:50:23 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dict/create_dict.h"
#include "../dict/set_value.h"
#include "../errors.h"
#include "../print/put_str.h"
#include "../utils/copy_strlen.h"
#include "../utils/get_file_size.h"
#include "parse_dict_file.h"
#include "parse_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(const char *dict_path, ssize_t file_size)
{
	char	*parsed_str;
	int		fd;

	parsed_str = malloc(sizeof(char) * (file_size + 1));
	if (parsed_str == NULL)
		return (NULL);
	fd = open(dict_path, O_RDONLY);
	read(fd, parsed_str, file_size);
	close(fd);
	parsed_str[file_size] = '\0';
	return (parsed_str);
}

long	read_line(char *str, char **line)
{
	long	length;

	length = 0;
	while (str[length] && str[length] != '\n')
		length++;
	*line = copy_strlen(str, length);
	if (str[length] == '\n')
		length++;
	return (length);
}

bool	cleanup(char *key, char *value)
{
	free(key);
	free(value);
	return (false);
}

bool	parse_dict_str(char *str, t_dict *dict)
{
	char	*line;
	long	nb_read_chars;
	char	*key;
	char	*value;
	int		parse_status;

	nb_read_chars = read_line(str, &line);
	while (nb_read_chars)
	{
		parse_status = parse_line(line, &key, &value);
		free(line);
		if (parse_status > 0)
		{
			if (!set_value(dict, key, value))
				return (cleanup(key, value));
		}
		else if (parse_status < 0)
			return (false);
		str += nb_read_chars;
		nb_read_chars = read_line(str, &line);
	}
	return (true);
}

int	parse_dict_file(const char *dict_path, t_dict *dict)
{
	int		fd;
	long	file_size;
	char	*dict_str;
	bool	parsed;

	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
		return (MISSING_DICT_ERROR_CODE);
	file_size = get_file_size(fd);
	close(fd);
	if (!file_size)
		return (EMPTY_DICT_ERROR_CODE);
	dict_str = read_file(dict_path, file_size);
	if (dict_str == NULL)
		return (TOO_LARGE_DICT_ERROR_CODE);
	*dict = create_dict();
	parsed = parse_dict_str(dict_str, dict);
	free(dict_str);
	if (!parsed)
		return (DICT_PARSING_ERROR_CODE);
	return (NO_ERROR_CODE);
}
