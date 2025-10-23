/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strlen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:34 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/18 19:51:38 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_STRLEN_H
# define COPY_STRLEN_H

/// @brief copies length characters of str
/// @param str 
/// @param length 
/// @return a copy of str ending with '\0' if length >= 1, otherwise NULL
char	*copy_strlen(char *str, long length);

#endif