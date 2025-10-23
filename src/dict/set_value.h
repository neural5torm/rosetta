/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:58:53 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:04:20 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VALUE_H
# define SET_VALUE_H

# include "dict_types.h"
# include <stdbool.h>

bool	set_value(t_dict *dict, char *key, char *value);

#endif