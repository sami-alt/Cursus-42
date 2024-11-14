#ifndef  BSQ_H
# define BSQ_H

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct s_map{
    int cols;
    int rows;
    char empty_char;
    char full_char;
    char obstacle_char;
    char **map;
} t_map;

typedef struct s_solution{
    int x;
    int y;
    int size;
} t_solution;

extern void	separator(t_map *file_info, t_solution *solution_info, int row, int col, int size);
extern void	expander(t_map *file_info, t_solution *solution_info, int row, int col);
extern void	solver(t_map *file_info, t_solution *solution_info);
extern int ft_atoi(char *numbers);
extern void    bsq(char *filepath);
extern int ft_atoi(char *numbers);
extern void openFile(char *filepath, t_map *file_info);
extern void freeMem(char **map, int rows);

#endif
