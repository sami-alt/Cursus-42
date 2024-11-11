#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*s1;
	const char	*set;
	const char	*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = ft_strtrim(test->s1, test->set);

	if (actual && strcmp(actual, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;
	free(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Trim characters from the beginning and end
		{"  Hello, World!  ", " ", "Hello, World!", 0},
		// Case 2: Trim characters from the start only
		{"\t\tHello", "\t", "Hello", 0},
		// Case 3: Trim characters from the end only
		{"Goodbye!!", "!", "Goodbye", 0},
		// Case 4: No characters to trim (input and set do not overlap)
		{"abcdef", "xyz", "abcdef", 0},
		// Case 5: All characters should be trimmed (input entirely in set)
		{"*****", "*", "", 0},
		// Case 6: Empty string as input
		{"", "xyz", "", 0},
		// Case 7: Empty set (no trimming should occur)
		{"Hello, World!", "", "Hello, World!", 0},
		// Case 8: Trim non-printable characters
		{"\n\nHello, World!\n\n", "\n", "Hello, World!", 0},
		// Case 9: Trim with set that overlaps part of the string
		{"---trim this---", "-", "trim this", 0},
		// Case 10: Empty input and empty set
		{"", "", "", 0},
		{NULL, NULL, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRTRIM - " RESET);
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
