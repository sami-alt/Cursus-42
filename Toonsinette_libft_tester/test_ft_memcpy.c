#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_test_result
{
	char		dest[50];
	char		src[50];
	size_t		n;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*expected = memcpy(test->dest, test->src, test->n);
	char	*actual = ft_memcpy(test->dest, test->src, test->n);

	if (memcmp(expected, actual, test->n) == 0)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Basic copying
		{{"Hello, World!"}, {"Goodbye!"}, 8, 0},
		{{"Hello, World!"}, {"42"}, 2, 0},
		{{"Test"}, {"12345"}, 5, 0},

		// Copying partial data
		{{"Buffer 1"}, {"Buffer 2"}, 4, 0},

		// Copying to the same destination
		{{"Same source"}, {"Same source"}, 10, 0},

		// Copy zero bytes
		{{"No Change"}, {"Won't Change"}, 0, 0},

		// Overlapping memory regions (undefined behavior in memcpy)
		{{"OverlappingTest"}, {"OverlappingTest"}, 7, 0},
		
		// Larger n values
		{{"Large Copy"}, {"1234567890ABCDEFGHIJKL"}, 20, 0},

		// Empty buffers
		{{"Existing"}, {""}, 1, 0},
		{{""}, {"Ginyu"}, 5, 0},
		{{""}, {""}, 5, 0},

		// Long string to short destination
		{{"Short"}, {"Longer String"}, 5, 0},

		// Sentinel to mark end of tests
		{{""}, {""}, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]) - 1;

	printf(BLUE "FT_MEMCPY - " RESET);
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
