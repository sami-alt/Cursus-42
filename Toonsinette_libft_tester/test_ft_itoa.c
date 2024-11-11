#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

typedef struct s_test_result
{
	int			input;
	char		*expected;
	char		*actual;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	test->actual = ft_itoa(test->input);
	if (test->actual == NULL && test->expected == NULL)
	{
		test->passed = 1;
		return ;
	}
	if (test->actual == NULL || test->expected == NULL)
	{
		test->passed = 0;
		return ;
	}
	if (strcmp(test->expected, test->actual) == 0)
		test->passed = 1;
	else
		test->passed = 0;
	free(test->actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		// Simple cases
		{0, "0", NULL, 0},
		{1, "1", NULL, 0},
		{-1, "-1", NULL, 0},
		{42, "42", NULL, 0},
		{-42, "-42", NULL, 0},
		
		// Edge cases
		{INT_MAX, "2147483647", NULL, 0},
		{INT_MIN, "-2147483648", NULL, 0},
		
		// Larger numbers
		{123456789, "123456789", NULL, 0},
		{-123456789, "-123456789", NULL, 0},
		
		// Single digit
		{7, "7", NULL, 0},
		{-7, "-7", NULL, 0},
		
		// Zero with negative sign
		{-0, "0", NULL, 0},
	};
	
	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]);
	int	i;
	
	printf(BLUE "FT_ITOA - " RESET);
	for (i = 0; i < total_tests; i++)
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
