/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** tab.c
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

void    display_tab(char **map, int lines)
{
	int i = 0;

	while (i < lines)
		my_put_str(map[i++]);
}

char    **create_tab(int columns, int lines)
{
	int i = 0;
	char **tab = NULL;

	tab = malloc(sizeof(char *) * lines);
	while (i < lines) {
		tab[i] = malloc(sizeof(char) * (columns + 1));
		i += 1;
	}
	return (tab);
}

char	*my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char    **insert_tab(char *arg, int columns, int lines)
{
	int fd = open(arg, O_RDONLY);
	int i = 0;
	int readen = 0;
	char buffer[columns];
	char **map = create_tab(columns, lines);

	read(fd, buffer, 1);
	while (buffer[0] != '\n')
		read(fd, buffer, 1);
	while (i < lines) {
		readen = read(fd, buffer, columns);
		buffer[readen] = '\0';
		my_strcpy(map[i], buffer);
		i += 1;
	}
	close(fd);
	return (map);
}

int     **create_tab_int(int columns, int lines)
{
	int i = 0;
	int **tab = malloc(sizeof(int *) * lines);

	while (i < lines) {
		tab[i] = malloc(sizeof(int) * (columns));
		i += 1;
	}
	return (tab);
}