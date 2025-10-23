/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:18:13 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:04:41 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_dict.h"
#include <stdlib.h>

t_dict	create_dict(void)
{
	int		i;
	t_dict	dict;

	i = 0;
	while (i < MAX_ITEMS)
		dict.items[i++] = NULL;
	return (dict);
}
