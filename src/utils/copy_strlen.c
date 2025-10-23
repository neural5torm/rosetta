/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:33:13 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/18 19:51:23 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copy_strlen.h"
#include <stdlib.h>

char	*copy_strlen(char *str, long length)
{
	char	*copied;
	int		i;

	if (length == 0)
		return (NULL);
	copied = malloc(sizeof(char) * (length + 1));
	if (copied == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copied[i] = str[i];
		i++;
	}
	copied[length] = '\0';
	return (copied);
}
