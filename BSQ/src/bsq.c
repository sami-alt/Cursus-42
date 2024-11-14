#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include "bsq.h"

void openFile(char *filepath, t_map *file_info);

void bsq(char *filepath)
{   
    
    t_map   *file_info;
    t_solution *solution_info;

    solution_info = (t_solution *)malloc(sizeof(solution_info));
    file_info = (t_map *)malloc(sizeof(file_info));
    openFile(filepath, file_info);
    //int i = 0;
    // while(i < file_info->rows)
    //     printf("%s\n", file_info->map[i++]);

    //int j = 0;

    // while (i < 10){
    //     j = 0;
    //     while(j < 11)
    //     {
    //         printf("%c", file_info->map[i][j]);
    //         j++;
    //     }
    //     i++;
    //     printf("\n");
    // }

    printf("%c", file_info->map[0][0]);

    //solver(file_info, solution_info);
    //map_validation();
    //print(solution_info);
    freeMem(file_info->map, file_info->cols);
    free(file_info);
    free(solution_info);
}
