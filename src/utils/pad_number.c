/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:58:47 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 19:30:57 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pad_number.h"
#include "str_len.h"
#include <stdlib.h>

char	*pad_number(char *temp_number, char padding_char)
{
	int		length;
	int		padded_length;
	char	*padded;
	int		i;

	length = str_len(temp_number);
	padded_length = length;
	if (padded_length % 3)
		padded_length += 3 - padded_length % 3;
	padded = malloc((padded_length + 1) * sizeof(char));
	i = 0;
	while (i < padded_length - length)
		padded[i++] = padding_char;
	while (i < padded_length)
	{
		padded[i] = temp_number[i - padded_length + length];
		i++;
	}
	padded[padded_length] = '\0';
	free(temp_number);
	return (padded);
}
