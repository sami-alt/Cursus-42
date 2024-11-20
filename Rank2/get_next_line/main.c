#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	
	if (fd1 == -1)
		printf("file error\n");
	//get_next_line(fd1);
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd2));
	return (0);
}
