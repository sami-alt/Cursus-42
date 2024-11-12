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
		// ASCII range
		{0, 0, 0, 0},
		{127, 0, 0, 0},
		{65, 0, 0, 0},	// 'A'
		{48, 0, 0, 0},	// '0'
		
		// Non-ASCII characters
		{128, 0, 0, 0},
		{255, 0, 0, 0},
		{-1, 0, 0, 0},
		{-128, 0, 0, 0},
		{-300, 0, 0, 0},
		{300, 0, 0, 0},
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]);
	int	i;

	printf(BLUE "FT_ISASCII - " RESET);
	for (i = 0; i < total_tests; i++)
	{
		tests[i].expected = isascii(tests[i].input);
		tests[i].actual = ft_isascii(tests[i].input);
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
