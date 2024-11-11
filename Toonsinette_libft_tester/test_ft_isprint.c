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
		// Printable characters
		{' ', 0, 0, 0},
		{'A', 0, 0, 0},
		{'z', 0, 0, 0},
		{'0', 0, 0, 0},
		{'~', 0, 0, 0},	// Tilde (~), the last printable character
		
		// Non-printable characters
		{'\n', 0, 0, 0},
		{'\t', 0, 0, 0},
		{127, 0, 0, 0},	// DEL character, not printable
		
		// Extended ASCII and out-of-range values
		{128, 0, 0, 0},	// Extended ASCII, not printable
		{255, 0, 0, 0},	// Extended ASCII, not printable
		{-1, 0, 0, 0},	// Negative value, not printable
		{300, 0, 0, 0}	// Out-of-bound value
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]);
	int	i;

	printf(BLUE "FT_ISPRINT - " RESET);
	for (i = 0; i < total_tests; i++)
	{
		tests[i].expected = isprint(tests[i].input);
		tests[i].actual = ft_isprint(tests[i].input);
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
