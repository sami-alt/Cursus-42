
#include "bsq.h"

void process_firstline(char *buffer, t_map *file_info)
{   
    int numbers;
    char *first_line;

    first_line = buffer;
    numbers = atoi(first_line);

    file_info->cols = numbers;
    file_info->rows = numbers;

    while(*first_line >= '0' && *first_line <= '9')
        first_line++;
    file_info->empty_char = *first_line++;
    file_info->obstacle_char = *first_line++;
    file_info->full_char = *first_line;
}

void proccess_map(char *buffer, t_map *file_info)
{   
    int indexj;
    int indexi;

    indexi = 0;
    indexj = 0;
    while (*buffer != '\n')
        buffer++;
    buffer++;
    file_info->map = malloc(file_info->rows * sizeof(char*));
    while(indexi){
        file_info->map[indexi] = (char *)malloc(file_info->cols * sizeof(char) + 1);
        indexi++;
    }
    if(!file_info->map)
        return ;
    indexi = 0; 
    while (indexi < file_info->rows)
    {
        indexj = 0;
        // if(!(file_info->map[indexi]))
        //     //return ;
        //     freeMem(file_info->map, indexi);
        while(indexj < file_info->cols && *buffer != '\n' )    
            file_info->map[indexi][indexj++] = *buffer++;
        buffer++;
        indexi++;
    }
}

char *readToBuffer(int fd, int *size)
{
	int bufferSize;
	char *buffer;
	int bytesRead;

	bufferSize = 1024;
	buffer = (char*)malloc(bufferSize * sizeof(char));
	if (!buffer)
        write(2, "e" ,1);
	bytesRead = read(fd, buffer, bufferSize);
	if (bytesRead == -1)
	{
		printf("%s","Error reading file");
		free(buffer);
		return NULL;
	}
	*size = bytesRead;
	return (buffer);
}

void openFile(char *filepath, t_map *file_info)
{
    int fd;
    int size;
    char *buffer;
    fd = open(filepath, O_RDONLY);

    if (fd == -1){
        close(fd);
       return ;
    }
    size = 0;

    buffer = readToBuffer(fd, &size);
    process_firstline(buffer, file_info);
    proccess_map(buffer, file_info);
    free(buffer);
    close(fd);
}
