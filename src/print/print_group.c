/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:30:26 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 20:40:19 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dict/dict_types.h"
#include "../errors.h"
#include "print_digit.h"
#include "print_group.h"
#include "put_str.h"

#define HUNDRED "100"

int	print_hundreds(char hundred, t_dict dict)
{
	char	hundred_str[2];
	int		status;

	status = NO_ERROR_CODE;
	hundred_str[0] = hundred;
	hundred_str[1] = '\0';
	status += print_digit(hundred_str, dict);
	put_str(" ");
	status += print_digit(HUNDRED, dict);
	return (status);
}

int	print_teens(char dozens, char units, t_dict dict)
{
	char	teens[3];

	teens[0] = dozens;
	teens[1] = units;
	teens[2] = '\0';
	return (print_digit(teens, dict));
}

int	print_dozens(char dozens, t_dict dict)
{
	char	dozen_str[3];

	dozen_str[0] = dozens;
	dozen_str[1] = '0';
	dozen_str[2] = '\0';
	return (print_digit(dozen_str, dict));
}

int	print_units(char units, t_dict dict)
{
	char	unit_str[2];

	unit_str[0] = units;
	unit_str[1] = '\0';
	return (print_digit(unit_str, dict));
}

int	print_group(char *digits, t_dict dict)
{
	int	status;

	status = NO_ERROR_CODE;
	if (digits[0] != '0')
	{
		status += print_hundreds(digits[0], dict);
		put_str(" ");
	}
	if (digits[1] != '0')
	{
		if (digits[1] == '1')
			status += print_teens(digits[1], digits[2], dict);
		else
			status += print_dozens(digits[1], dict);
		put_str(" ");
	}
	if (digits[2] != '0')
	{
		status += print_units(digits[2], dict);
		put_str(" ");
	}
	return (status);
}
