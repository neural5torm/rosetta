/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:00:51 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:04:41 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_value.h"
#include "../utils/str_equals.h"
#include <stdbool.h>
#include <stdlib.h>

bool	set_value(t_dict *dict, char *key, char *value)
{
	int	i;

	i = 0;
	while (i < MAX_ITEMS && dict->items[i])
	{
		if (str_equals(dict->items[i]->key, key))
		{
			dict->items[i]->value = value;
			return (true);
		}
		i++;
	}
	if (i == MAX_ITEMS)
		return (false);
	dict->items[i] = malloc(sizeof(t_item));
	if (!dict->items[i])
		return (false);
	dict->items[i]->key = key;
	dict->items[i]->value = value;
	return (true);
}
