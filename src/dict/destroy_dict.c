/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:05:45 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:51:01 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destroy_dict.h"
#include <stdlib.h>

void	destroy_dict(t_dict *dict)
{
	int	i;

	if (dict == NULL)
		return ;
	i = 0;
	while (i < MAX_ITEMS)
	{
		if (dict->items[i])
		{
			free(dict->items[i]->key);
			free(dict->items[i]->value);
		}
		free(dict->items[i]);
		i++;
	}
}
