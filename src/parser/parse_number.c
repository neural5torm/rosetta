/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:08:25 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 11:15:03 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/copy_strlen.h"
#include "parse_number.h"
#include <stdlib.h>

long	count_non_significant(char *nbr, long length)
{
	long	i;

	if (length == 1)
		return (0);
	i = 0;
	while (i < length)
	{
		if (nbr[i] != '0')
			break ;
		i++;
	}
	return (i);
}

char	*parse_number(char *nbr, long length)
{
	long	i;
	long	non_significant;

	i = 0;
	while (i < length)
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			break ;
		i++;
	}
	non_significant = count_non_significant(nbr, i);
	return (copy_strlen(nbr + non_significant, i - non_significant));
}
