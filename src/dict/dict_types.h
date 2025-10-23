/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:31:53 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 18:12:01 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_TYPES_H
# define DICT_TYPES_H

# define MAX_ITEMS 1024

typedef struct s_item
{
	char			*key;
	char			*value;
}					t_item;

typedef struct s_dict
{
	struct s_item	*items[MAX_ITEMS];
}					t_dict;

#endif