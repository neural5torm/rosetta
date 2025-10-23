/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:17:15 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 16:17:59 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_VALUE_H
# define GET_VALUE_H

# include "dict_types.h"

/// @brief finds the corresponding value for the key in the dictionary
/// @param dict
/// @param key
/// @return returns the string value if key found, otherwise NULL
char	*get_value(t_dict dict, char *key);

#endif