#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*s1;
	const char	*s2;
	const char	*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = ft_strjoin(test->s1, test->s2);

	if (actual && strcmp(actual, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;

	free(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		// Regular strings
		{"Hello", "World", "HelloWorld", 0},
		{"42", "Network", "42Network", 0},
		{"Libft", "Test", "LibftTest", 0},
		
		// Empty strings
		{"", "Hello", "Hello", 0},
		{"Hello", "", "Hello", 0},
		{"", "", "", 0},
		
		// Mixed cases
		{"abc", "123", "abc123", 0},
		{"  ", "spaces", "  spaces", 0},
		
		// Large string
		{"LongString1", "LongString2", "LongString1LongString2", 0},

		{NULL, NULL, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRJOIN - " RESET);
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
