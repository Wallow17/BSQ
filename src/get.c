/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** get.c
*/

#include "my.h"

int     get_lines(char *arg)
{
	int i = -1;
	int fd = open(arg, O_RDONLY);
	int lines = 0;
	char buffer[1];
	char line[10];

	while ((++i) < 10)
		line[i] = '\0';
	i = 0;
	if (fd == -1)
		return (-1);
	read(fd, buffer, 1);
	while (buffer[0] != '\n') {
		if (buffer[0] < '0' || buffer[0] > '9')
			return (-1);
		line[i++] = buffer[0];
		read(fd, buffer, 1);
	}
	lines = my_getnbr(line);
	close (fd);
	return (lines);
}

int     get_columns(char *arg)
{
	int i = 0;
	int size = 255;
	int len = 0;
	int fd = open(arg, O_RDONLY);
	char buffer[size];

	if (fd == -1)
		return (-1);
	read(fd, buffer, size);
	while (buffer[i] != '\n')
		i += 1;
	while (buffer[++i] != '\n') {
		if (i == size) {
			read(fd, buffer, size);
			i = 0;
		}
		len += 1;
	}
	close(fd);
	return (len);
}