#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*big;
	const char	*little;
	size_t		len;
	const char	*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = ft_strnstr(test->big, test->little, test->len);
	if ((actual == NULL && test->expected == NULL) || (actual && test->expected && strcmp(actual, test->expected) == 0))
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Substring at the beginning
		{"Hello, World!", "Hello", 13, "Hello, World!", 0},
		// Case 2: Substring at the end
		{"Hello, World!", "World!", 13, "World!", 0},
		// Case 3: Substring is not found
		{"Hello, World!", "42", 13, NULL, 0},
		// Case 4: Empty substring (should return the original string)
		{"Hello, World!", "", 13, "Hello, World!", 0},
		// Case 5: len smaller than the position of substring
		{"Hello, World!", "World", 5, NULL, 0},
		// Case 6: len is zero
		{"Hello, World!", "World", 0, NULL, 0},
		// Case 7: Substring is longer than len
		{"Hello, World!", "World", 3, NULL, 0},
		// Case 8: Empty string to search in
		{"", "Hello", 5, NULL, 0},
		// Case 9: Searching for an empty string in an empty string
		{"", "", 5, "", 0},
		// Case 10: Substring overlaps with the len limit
		{"1234567890", "67890", 9, NULL, 0},
		{NULL, NULL, 0, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRNSTR - " RESET);
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
