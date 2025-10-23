/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:18:37 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 16:19:48 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_value.h"
#include "../utils/str_equals.h"
#include <stdlib.h>

char	*get_value(t_dict dict, char *key)
{
	int	i;

	i = 0;
	while (i < MAX_ITEMS && dict.items[i])
	{
		if (str_equals(dict.items[i]->key, key))
			return (dict.items[i]->value);
		i++;
	}
	return (NULL);
}
