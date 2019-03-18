/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_biggest {
	int value;
	int i;
	int j;
} t_biggest;

int             get_columns(char *arg);
int             get_lines(char *arg);
int             my_getnbr(char *res);
char	        *my_strcpy(char *dest, char *src);
void            display_tab(char **map, int lines);
char            **insert_tab(char *arg, int columns, int lines);
char            **create_tab(int columns, int lines);
int             **create_tab_int(int columns, int lines);
int             verif_min(int **map_bin, int i, int j);
int             **transform_tab(char **map, int columns, int lines);
t_biggest       find_biggest(char **map, int columns, int lines);
char            **fill_biggest(char **map, t_biggest biggest);
int		my_put_char(char c);
int		my_put_str(char const *str);

#endif