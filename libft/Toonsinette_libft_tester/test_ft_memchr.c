#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*buffer;
	int			c;
	size_t		n;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	const void	*expected  = memchr(test->buffer, test->c, test->n);
	const void	*actual = ft_memchr(test->buffer, test->c, test->n);
	size_t	expected_index = (unsigned char *)expected - (unsigned char *)test->buffer;
	size_t	actual_index = (unsigned char *)actual - (unsigned char *)test->buffer;

	if (expected == NULL && actual == NULL)
		test->passed = 1;
	else if (expected != NULL && actual != NULL)
	{
		if (expected_index == actual_index)
			test->passed = 1;
		else
			test->passed = 0;
	}
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Basic cases
		{"Hello, World!", 'W', 13, 0},
		{"Hello, World!", 'H', 13, 0},
		{"Hello, World!", '!', 13, 0},
		
		// Character not present
		{"Hello, World!", 'z', 13, 0},
		
		// Search zero bytes
		{"Hello, World!", 'H', 0, 0},
		
		// Search entire buffer
		{"Hello, World!", 'o', 13, 0},
		
		// Multiple occurrences
		{"Hello, World!", 'l', 13, 0},
		
		// Search for null terminator
		{"Hello, World!", '\0', 13, 0},
		
		// Extended ASCII characters
		{ "Byte \xFF Test", '\xFF', 11, 0},
		{ "Byte \xFF Test", 'B', 11, 0},
		
		// Empty buffer
		{"", 'A', 1, 0},
		
		// Buffer with all identical characters
		{"AAAAAA", 'A', 6, 0},
		
		// Large buffer
		{ "This is a longer string used to test ft_memchr functionality.", 't', 60, 0},
		
		// Boundary conditions
		{"Boundary", 'B', 1, 0},
		{"Boundary", 'y', 8, 0},
		{"Boundary", 'n', 8, 0},
		
		// Negative and out-of-range values for 'c' (since 'c' is an int)
		{"Negative Test", -1, 13, 0},
		{"Out of Range", 256, 12, 0},
		
		// Sentinel to mark end of tests
		{NULL, 0, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]) - 1;

	printf(BLUE "FT_MEMCHR - " RESET);
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
