#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_test_result
{
	char		dest[200];
	int			c;
	size_t		n;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	dest_copy[200];
	strcpy(dest_copy, test->dest);
	char	*expected = memset(dest_copy, test->c, test->n);
	char	*actual = ft_memset(test->dest, test->c, test->n);
	if (memcmp(expected, actual, test->n) == 0)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Basic functionality
		{{"Hello, World!"}, 'A', 5, 0},
		{{"Test"}, 'x', 3, 0},
		{{"Buffer"}, '1', 6, 0},
		
		// Filling entire buffer
		{{"Fill this"}, '*', 9, 0},
		
		// Set zero bytes (no change)
		{{"No Change"}, 'B', 0, 0},
		
		// Fill with non-printable characters
		{{"Non-printable"}, '\xFF', 5, 0},
		
		// Fill large buffer
		{{"Large"}, 'L', 100, 0},
		
		// Buffer containing null terminator before memset
		{{"Test\0WithNull"}, 'Z', 10, 0},

		// Fill with null characters
		{{"Fill with null"}, '\0', 5, 0},

		// Sentinel to mark end of tests
		{{""}, 0, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]) - 1;

	printf(BLUE "FT_MEMSET - " RESET);
	for (int i = 0; i < total_tests; i++)
	{
		run_test(&tests[i]);
		if (tests[i].passed)
			passed_tests++;
		else
			failed_tests++;
	}
	printf("Total Tests: %d -> ", total_tests);
	printf(GREEN " %d✅\n" RESET, passed_tests);
	if (failed_tests > 0)
		printf(RED " %d❌\n" RESET, failed_tests);

	return (failed_tests == 0) ? 0 : 1;
}
