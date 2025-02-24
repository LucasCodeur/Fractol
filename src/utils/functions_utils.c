/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:31:29 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:03 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static long double str_to_double(char *str, int *i)
{
    double  integer_part;
    double  fractional_part;
    int	    number_of_decimal;
    t_bool  dot_encounter;

    dot_encounter = FALSE;
    integer_part = 0.0;
    fractional_part = 0.0;
    number_of_decimal = 0.0;
    while (str[*i] != '\0' && str[*i] != ' ')
    {
	if (str[*i] == '.')
	{
	    dot_encounter = TRUE;
	    (*i)++;
	}
	if (dot_encounter == FALSE)
	    integer_part = integer_part * 10 + (str[*i] - 48);
	else
	{
	    fractional_part = fractional_part * 10 + (str[*i] - 48);
	    number_of_decimal++;
	}
	(*i)++;
    }
    return (integer_part + fractional_part / pow(10, number_of_decimal)); 
}

void	ft_atod(t_cn *c, char *str, t_bool *error)
{
    int		i;
    long double	check_overflow;
    long double	check_overflow_2;

    i = 0;
    check_overflow = str_to_double(str, &i); 
    i++;
    check_overflow_2 = str_to_double(str, &i); 
    if (check_overflow > DBL_MAX || check_overflow_2 > DBL_MAX)
    {
	*error = TRUE;
	return ;
    }
    c->r = check_overflow;
    c->i = check_overflow_2;
    return ;
}


