/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** bsq.c
*/

#include "my.h"
#include <stdlib.h>

int     verif_min(int **map_bin, int i, int j)
{
	int temp = map_bin[i][j - 1];

	if (map_bin[i - 1][j - 1] < temp)
		temp = map_bin[i - 1][j - 1];
	if (map_bin[i - 1][j] < temp)
		temp = map_bin[i - 1][j];
	return (temp + 1);
}

char    **fill_biggest(char **map, t_biggest biggest)
{
	int i = biggest.i - (biggest.value - 1);
	int j = biggest.j - (biggest.value - 1);

	while (i <= biggest.i) {
		while (j <= biggest.j) {
			map[i][j] = 'x';
			j += 1;
		}
		j = biggest.j - (biggest.value - 1);
		i += 1;
	}
	return (map);
}

t_biggest       algo(int **map_bin, int i, int j, t_biggest biggest)
{
	if (i == 0 || j == 0)
		map_bin[i][j] = 1;
	else
		map_bin[i][j] = verif_min(map_bin, i, j);
	if (map_bin[i][j] > biggest.value) {
		biggest.value = map_bin[i][j];
		biggest.i = i;
		biggest.j = j;
	}
	return (biggest);
}

t_biggest       find_biggest(char **map, int columns, int lines)
{
	t_biggest biggest = { 0, 0, 0 };
	int i = -1;
	int j = -1;
	int **map_bin = create_tab_int(columns, lines);

	while ((++i) < lines) {
		while ((++j) < columns) {
			if (map[i][j] == 'o')
				map_bin[i][j] = 0;
			else if (map[i][j] == '.')
				biggest = algo(map_bin, i, j, biggest);
			else
				map_bin[i][j] = 0;
		}
		j = -1;
	}
	free(map_bin);
	return (biggest);
}

int     main(int ac, char **av)
{
	t_biggest biggest;
	int lines = get_lines(av[1]);
	int columns = get_columns(av[1]);
	char **map;

	if (ac != 2)
		return (write(0, "[BSQ] Usage: ./bsq <PATH>.\n", 27), 84);
	if (lines == -1 || columns == -1)
		return (write(0, "[BSQ] Error: Incorrect map.\n", 28), 84);
	map = insert_tab(av[1], columns + 1, lines + 1);
	biggest = find_biggest(map, columns, lines);
	fill_biggest(map, biggest);
	display_tab(map, lines + 1);
	free(map);
	return (0);
}