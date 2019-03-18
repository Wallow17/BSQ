/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_put_str.c
*/

#include "my.h"

int	my_put_str(char const *str)
{
	int	a = 0;

	while (str[a] != '\0') {
		my_put_char(str[a]);
		a++;
	}
	return (0);
}