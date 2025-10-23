/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <osasburg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:18:00 by osasburg          #+#    #+#             */
/*   Updated: 2025/10/19 10:44:30 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_NUMBER_H
# define PARSE_NUMBER_H

/// @brief parses nbr for a number atoi-style 
/// @param nbr 
/// @param length 
/// @return returns a copy of the number if found, otherwise NULL
char	*parse_number(char *nbr, long length);

#endif