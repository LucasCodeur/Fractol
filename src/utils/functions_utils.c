/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:31:29 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 15:09:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

double ft_convert_one_double(char *str)
{
    double  integer_part;
    double  fractional_part;
    int	    number_of_decimal;
    t_bool  dot_encounter;

    dot_encounter = FALSE;
    integer_part = 0.0;
    fractional_part = 0.0;
    number_of_decimal = 0.0;
    while (*str != '\0')
    {
	if (*str == '.')
	{
	    dot_encounter = TRUE;
	    str++;
	}
	if (dot_encounter == FALSE)
	    integer_part = integer_part * 10 + (*str - 48);
	else
	{
	    fractional_part = fractional_part * 10 + (*str - 48);
	    number_of_decimal++;
	}
	str++;
    }
    return (integer_part + fractional_part / pow(10, number_of_decimal)); 
}
