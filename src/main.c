/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:56:59 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 19:33:15 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict/destroy_dict.h"
#include "dict/dict_types.h"
#include "errors.h"
#include "main.h"
#include "parser/parse_dict_file.h"
#include "parser/parse_number.h"
#include "print/print_number.h"
#include "print/put_str.h"
#include "utils/pad_number.h"
#include "utils/str_len.h"
#include <stdbool.h>
#include <stdlib.h>

bool	is_valid_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	parse_args(int argc, char **argv, char **dict_path, char **parsed_number)
{
	char	*number;

	*dict_path = DEFAULT;
	if (argc == 2)
		number = argv[1];
	else if (argc == 3)
	{
		*dict_path = argv[1];
		number = argv[2];
	}
	else
		return (BAD_ARG_ERROR_CODE);
	if (!is_valid_number(number))
		return (BAD_NBR_ERROR_CODE);
	else
		*parsed_number = pad_number(parse_number(number, str_len(number)), '0');
	return (NO_ERROR_CODE);
}

int	handle_error(int code)
{
	if (code >= 20)
		put_err(DICT_ERROR_MSG);
	else
		put_err(ERROR_MSG);
	return (code);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	t_dict	dict;
	char	*number_to_print;
	int		error_code;

	error_code = 0;
	error_code = parse_args(argc, argv, &dict_path, &number_to_print);
	if (error_code)
		return (handle_error(error_code));
	error_code = parse_dict_file(dict_path, &dict);
	if (error_code)
		return (handle_error(error_code));
	error_code = print_number(number_to_print, dict);
	free(number_to_print);
	destroy_dict(&dict);
	if (error_code)
		return (handle_error(error_code));
	return (NO_ERROR_CODE);
}
