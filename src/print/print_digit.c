/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:26:29 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 20:36:37 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dict/dict_types.h"
#include "../dict/get_value.h"
#include "../errors.h"
#include "print_digit.h"
#include "put_str.h"
#include <stdlib.h>

int	print_digit(char *digit, t_dict dict)
{
	char	*value;

	value = get_value(dict, digit);
	if (value == NULL)
		return (MISSING_DICT_KEY_ERROR_CODE);
	put_str(value);
	return (NO_ERROR_CODE);
}
