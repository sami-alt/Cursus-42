#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	size_t	actual_len = ft_strlcat(actual_dest, test->src, test->size);
	if (actual_len == test->expected_len && strcmp(actual_dest, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	// Define test cases
	t_test_result	tests[] = {
		// Case 1: Basic concatenation with sufficient space
		{"Hello", " World", 100, 11, "Hello World", 0},
		// Case 2: Not enough space (size < strlen(dest) + strlen(src))
		{"Hello", " World", 10, 11, "Hello Wor", 0},
		// Case 3: No space left in destination (size <= strlen(dest))
		{"Hello", " World", 5, 11, "Hello", 0},
		// Case 4: Empty destination buffer
		{"", "Hello", 10, 5, "Hello", 0},
		// Case 5: Empty source buffer
		{"Hello", "", 10, 5, "Hello", 0},
		// Case 6: Empty source and destination buffers
		{"", "", 10, 0, "", 0},
		// Case 7: Size = 0 (buffer cannot hold any content)
		{"Hello", "World", 0, 5, "Hello", 0},
		// Case 8: Exact fit (size = strlen(dest) + strlen(src) + 1)
		{"Hello", "World", 11, 10, "HelloWorld", 0},

		{{""}, NULL, 0, 0, {""}, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRLCAT - " RESET);
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
