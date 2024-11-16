#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	
	int fd;
	size_t bytes;
	char *buffer =  (char *)malloc(20 * sizeof(char));

	fd = open("test.txt", O_RDONLY);

	if (fd == -1)
			printf("File open error");
	bytes = read(fd, buffer, 20);
	buffer[20] = '\0';
	
	printf("%s\n", buffer);

	return (0);
}
