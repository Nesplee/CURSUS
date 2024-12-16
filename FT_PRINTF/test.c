/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:25:00 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/16 07:29:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	    int	value = 42;
		int *ptr = &value;

    // Test 1: Simple string
    ft_printf("Test 1: Hello, world!\n");

    // Test 2: Character
    ft_printf("Test 2: Character: %c\n", 'A');

    // Test 3: String
    ft_printf("Test 3: String: %s\n", "Hello");

    // Test 4: Integer
    ft_printf("Test 4: Integer: %d\n", 42);

    // Test 5: Unsigned Integer
    ft_printf("Test 5: Unsigned Integer: %u\n", 42);

    // Test 6: Hexadecimal (lowercase)
    ft_printf("Test 6: Hexadecimal: %x\n", 42);

    // Test 7: Hexadecimal (uppercase)
    ft_printf("Test 7: Hexadecimal: %X\n", 42);

    // Test 8: Pointer
    ft_printf("Test 8: Pointer: %p\n", ptr);

    // Test 9: Percent sign
    ft_printf("Test 9: Percent: %%\n");

	ft_printf("Test 10: Mixed: %d, %u, %x, %X, %p, %c, %s, %%\n", -42, 42, 42, 42, ptr, 'A', "Hello");

    return 0;
}
