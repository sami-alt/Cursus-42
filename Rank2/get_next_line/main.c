#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

int main(){


	assert(get_next_line(47382) == NULL);
	assert(get_next_line(1023) == NULL);
	assert(get_next_line(-1) == NULL);

	int fd1, fd2, fd3, fd4;
	char *line;	

	fd1 = open("test.txt", O_RDONLY);
	while((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);

	fd1 = open("empty.txt", O_RDONLY);
	line = get_next_line(fd2);
	if(line == NULL)
	{
		printf("Empty file return null\n");
	} else {
		printf("Unexpected content %s", line);
		free(line);
	} 
	close(fd2);
	free(line);
	line = NULL;
	fd3 = open("longline.txt", O_RDONLY);
	line = get_next_line(fd3);
	if(line) {
		printf("%s\n", line);
		free(line);
	}else{
		printf("No content read");
	}
	close(fd3);


	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	line = NULL;
	while (1)
	{
		line = get_next_line(fd1);
		if (line) {
			printf("Line from test1.txt: %s", line);
			free(line);
		} else
			break;
		line = get_next_line(fd2);
		if (line) {
			printf("Line from test2.txt: %s", line);
			free(line);
		} else
			break;
		line = get_next_line(fd3);
		if (line)
		{
			printf("Line from test3.txt: %s", line);
			free(line);
		} else
			break;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	printf("End of test1.txt reached.\n\n");

	while ((line = get_next_line(STDIN_FILENO)) != NULL){
		printf("%s", line);
		free(line);
	}

	return (0);
}
