#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*s1;
	const char	*s2;
	size_t		n;
	int			expected;
	int			actual;
	int			passed;
}	t_test_result;

int	normalize_result(int result)
{
	if (result < 0)
		return (-1);
	else if (result > 0)
		return (1);
	else
		return (0);
}

void	run_test(t_test_result *test)
{
	test->actual = ft_strncmp(test->s1, test->s2, test->n);
	test->expected = normalize_result(strncmp(test->s1, test->s2, test->n));
	test->actual = normalize_result(test->actual);
	if (test->expected == test->actual)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	// Define test cases
	t_test_result	tests[] = {
		// Case 1: Equal strings
		{"Hello, World!", "Hello, World!", 13, 0, 0, 0},
		// Case 2: Different strings, first string greater
		{"abcdef", "abcdee", 6, 1, 1, 0},
		// Case 3: Different strings, first string smaller
		{"abcdee", "abcdef", 6, -1, -1, 0},
		// Case 4: Strings identical up to n characters
		{"Hello, World!", "Hello, there!", 7, 0, 0, 0},
		// Case 5: n is 0
		{"Hello", "World", 0, 0, 0, 0},
		// Case 6: n greater than string lengths
		{"Short", "Short", 100, 0, 0, 0},
		// Case 7: Empty strings
		{"", "", 5, 0, 0, 0},
		// Case 8: First string empty
		{"", "Non-empty", 10, -1, -1, 0},
		// Case 9: Second string empty
		{"Non-empty", "", 10, 1, 1, 0},
		// Case 10: Both strings empty, n = 0
		{"", "", 0, 0, 0, 0},
		// Case 11: Strings with special characters
		{"Spécial", "Spécial", 7, 0, 0, 0},
		// Case 12: Strings with different cases
		{"CaseSensitive", "casesensitive", 13, -1, -1, 0},
		// Case 13: Strings with non-printable characters
		{"Hello\x01", "Hello\x02", 7, -1, -1, 0},
		// Case 14: n is exactly the length of the shorter string
		{"Exact", "Exact", 5, 0, 0, 0},
		// Case 15: n exceeds the length of the first string
		{"Short", "Shorter", 10, -1, -1, 0},
		// Sentinel to mark end of tests
		{NULL, NULL, 0, 0, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRNCMP - " RESET);
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
