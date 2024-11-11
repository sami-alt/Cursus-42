#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	char		dest[100];
	const char	*src;
	size_t		size;
	size_t		expected_len;
	char		expected[100];
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	actual_dest[100];
	strcpy(actual_dest, test->dest);
	size_t	actual_len = ft_strlcpy(actual_dest, test->src, test->size);
	if (actual_len == test->expected_len && strcmp(actual_dest, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Basic copy with enough space
		{"", "Hello, World!", 100, 13, "Hello, World!", 0},
		// Case 2: Copy with buffer smaller than source (truncated)
		{"", "Hello, World!", 6, 13, "Hello", 0},
		// Case 3: No space to copy (size == 0)
		{"", "Hello, World!", 0, 13, "", 0},
		// Case 4: Empty source string
		{"ExistingData", "", 10, 0, "", 0},
		// Case 5: Copy exactly fitting the destination size (size == strlen(src) + 1)
		{"", "Hello", 6, 5, "Hello", 0},
		// Case 6: Copy with size = 1 (only null terminator should be copied)
		{"ExistingData", "Hello", 1, 5, "", 0},
		{{""}, NULL, 0, 0, {""}, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRLCPY - " RESET);
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
