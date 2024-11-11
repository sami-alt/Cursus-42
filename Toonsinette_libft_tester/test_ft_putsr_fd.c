#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	char	*s;
	int		fd;
	char	expected[100];
	int		passed;
}	t_test_result;

int	check_file_content(const char *filename, const char *expected)
{
	char	buffer[200];
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
	int		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		test->passed = 0;
		return;
	}
	ft_putstr_fd(test->s, fd);
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
		{"Hello, World!", 1, "Hello, World!", 0},
		{"42", 1, "42", 0},
		{"", 1, "", 0},
		{"A longer string with multiple words.", 1, "A longer string with multiple words.", 0},
		{"\n", 1, "\n", 0},
		{"Special chars: !@#$%^&*()", 1, "Special chars: !@#$%^&*()", 0},
		{"\xFF\x00\x01", 1, "\xFF\x00\x01", 0},
		{NULL, 0, "", 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_PUTSTR_FD - " RESET);
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
