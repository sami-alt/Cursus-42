#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*str;
	size_t		expected_len;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	size_t	actual_len = ft_strlen(test->str);

	if (actual_len == test->expected_len)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Regular string
		{"Hello, World!", 13, 0},
		// Case 2: Empty string
		{"", 0, 0},
		// Case 3: String with numbers and letters
		{"42Network", 9, 0},
		// Case 4: String with special characters
		{"!@#$%^&*()", 10, 0},
		// Case 5: String with spaces
		{"This is a test.", 15, 0},
		// Case 6: String with non-printable characters
		{"\x01\x02\x03", 3, 0},
		// Case 7: Long string
		{"The quick brown fox jumps over the lazy dog.", 44, 0},
		{NULL, 0, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRLEN - " RESET);
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

