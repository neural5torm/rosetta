/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:36:49 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 20:33:58 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dict/get_value.h"
#include "../errors.h"
#include "../utils/copy_strlen.h"
#include "../utils/str_len.h"
#include "print_number.h"
#include "print_group.h"
#include "put_str.h"
#include <stdlib.h>

int	print_number(char *number, t_dict dict)
{
	int	i;
	int	length;
	int	status;

	status = NO_ERROR_CODE;
	length = str_len(number);
	i = 0;
	while (i < length)
	{
		status += print_group(number + i, dict);
		i += 3;
	}
	put_str("\n");
	return (status);
}
