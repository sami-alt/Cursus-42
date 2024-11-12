#include <stdio.h>
#include <ctype.h>
#include "libft.h"

typedef struct s_test_result
{
	int			input;
	int			expected;
	int			actual;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	test->actual = ft_toupper(test->input);
	test->expected = toupper(test->input);
	if (test->actual == test->expected)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	// Define test cases
	t_test_result	tests[] = {
		// Case 1: Lowercase letter
		{'a', 0, 0, 0},
		{'z', 0, 0, 0},
		{'m', 0, 0, 0},
		// Case 2: Uppercase letter (should remain unchanged)
		{'A', 0, 0, 0},
		{'Z', 0, 0, 0},
		{'M', 0, 0, 0},
		// Case 3: Non-alphabetic characters (should remain unchanged)
		{'1', 0, 0, 0},
		{'$', 0, 0, 0},
		{'@', 0, 0, 0},
		// Case 4: Non-printable characters
		{'\n', 0, 0, 0},
		{'\x01', 0, 0, 0},
		// Case 5: Extended ASCII characters
		{128, 0, 0, 0},
		{255, 0, 0, 0},

		{0, 0, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_TOUPPER - " RESET);
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
