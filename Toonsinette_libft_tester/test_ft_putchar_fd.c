#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	char	c;
	int		fd;
	char	expected[2];
	int		passed;
}	t_test_result;

int	check_file_content(const char *filename, const char *expected)
{
	char	buffer[10];
	int		fd;
	ssize_t	read_bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	read_bytes = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (read_bytes < 0)
		return (0);
	buffer[read_bytes] = '\0';
	return (strcmp(buffer, expected) == 0);
}

void	run_test(t_test_result *test, const char *filename)
{
	int	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		test->passed = 0;
		return;
	}
	ft_putchar_fd(test->c, fd);
	close(fd);
	if (check_file_content(filename, test->expected))
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	const char	*test_file = "test_output.txt";

	t_test_result	tests[] = {
		{'A', 1, "A", 0},
		{'B', 1, "B", 0},
		{'z', 1, "z", 0},
		{'0', 1, "0", 0},
		{'\n', 1, "\n", 0},
		{'\xFF', 1, "\xFF", 0},
		{'\0', 1, "\0", 0},
		{0, 0, "", 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_PUTCHAR_FD - " RESET);
	for (int i = 0; i < total_tests; i++)
	{
		run_test(&tests[i], test_file);
		if (tests[i].passed)
			passed_tests++;
		else
			failed_tests++;
	}
	printf("Total Tests: %d -> ", total_tests);
	printf(GREEN " %d✅\n" RESET, passed_tests);
	if (failed_tests > 0)
		printf(RED " %d❌\n" RESET, failed_tests);
	remove(test_file);

	return (failed_tests == 0) ? 0 : 1;
}
