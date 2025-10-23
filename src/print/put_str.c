/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:46:28 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 16:15:25 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/str_len.h"
#include <unistd.h>

void	put_str(char *str)
{
	write(STDOUT_FILENO, str, str_len(str));
}

void	put_err(char *str)
{
	write(STDERR_FILENO, str, str_len(str));
}
