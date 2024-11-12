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

int	main(void)
{
	t_test_result	tests[] = {
		// Alphabetic characters
		{'A', 0, 0, 0},
		{'Z', 0, 0, 0},
		{'a', 0, 0, 0},
		{'z', 0, 0, 0},
		
		// Non-alphabetic characters
		{'0', 0, 0, 0},
		{'9', 0, 0, 0},
		{'@', 0, 0, 0},
		{'[', 0, 0, 0},
		{'`', 0, 0, 0},
		{'{', 0, 0, 0},
		
		// Control characters
		{'\n', 0, 0, 0},
		{'\t', 0, 0, 0},
		{'\0', 0, 0, 0},
		
		// Extended ASCII characters
		{128, 0, 0, 0},
		{255, 0, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]);
	int	i;

	printf(BLUE "FT_ISALPHA - " RESET);
	for (i = 0; i < total_tests; i++)
	{
		tests[i].expected = isalpha(tests[i].input);
		tests[i].actual = ft_isalpha(tests[i].input);
		if ((tests[i].expected != 0 && tests[i].actual != 0) ||
			(tests[i].expected == 0 && tests[i].actual == 0))
			tests[i].passed = 1;
		else
			tests[i].passed = 0;

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
