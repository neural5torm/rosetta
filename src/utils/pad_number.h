/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_number.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:57:20 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 19:32:13 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAD_NUMBER_H
# define PAD_NUMBER_H

/// @brief creates a copy of number with at most 2 leading padding characters
/// @param temp_number the temporary number to pad; will be freed
/// @param padding the character used for padding
/// @return the padded copy of number
char	*pad_number(char *temp_number, char padding);

#endif