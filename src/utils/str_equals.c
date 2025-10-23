/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:20:23 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 13:45:43 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_equals.h"
#include "str_len.h"

bool	str_equals(char *str1, char *str2)
{
	int	length;
	int	i;

	length = str_len(str1);
	if (length != str_len(str2))
		return (false);
	i = 0;
	while (i < length)
	{
		if (str1[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}
