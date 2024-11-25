#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char  *line;

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

	// while ((line = get_next_line(STDIN_FILENO)) != NULL){
	// 	printf("%s", line);
	// 	free(line);
	// }

	return (0);
}
