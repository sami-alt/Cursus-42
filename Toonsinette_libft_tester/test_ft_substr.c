#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*str;
	unsigned int start;
	size_t		len;
	const char	*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = ft_substr(test->str, test->start, test->len);
	if (actual && strcmp(actual, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;
	free(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Extract substring from the middle
		{"Hello, World!", 7, 5, "World", 0},
		// Case 2: Extract substring from the start
		{"Hello, World!", 0, 5, "Hello", 0},
		// Case 3: Extract with len greater than available characters
		{"Hello, World!", 7, 20, "World!", 0},
		// Case 4: Extract with len = 0 (should return empty string)
		{"Hello, World!", 7, 0, "", 0},
		// Case 5: Start index beyond the length of the string
		{"Hello, World!", 50, 5, "", 0},
		// Case 6: Empty string as input
		{"", 0, 5, "", 0},
		// Case 7: Start at the end of the string
		{"Hello, World!", 12, 5, "!", 0},
		// Case 8: Extract entire string
		{"Entire string", 0, 13, "Entire string", 0},
		// Case 9: Extract with len longer than the string itself
		{"Short", 0, 50, "Short", 0},
		// Case 10: Start exactly at the string's length (should return an empty string)
		{"abcdef", 6, 5, "", 0},
		{NULL, 0, 0, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_SUBSTR - " RESET);
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
