#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*str;
	int			c;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*expected = strchr(test->str, test->c);
	char	*actual = ft_strchr(test->str, test->c);

	if (expected == actual)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		{"Hello, World!", 'H', 0},
		{"Hello, World!", 'W', 0},
		{"Hello, World!", '!', 0},
		{"Hello, World!", 'o', 0},
		{"Hello, World!", 'z', 0},
		{"Hello, World!", '\0', 0},
		{"", 'a', 0},
		{"", '\0', 0},
		{"abcabcabc", 'b', 0},
		{"abcabcabc", 'c', 0},
		{"abcabcabc", 'd', 0},
		{"abcdef", 'f', 0},
		{"abcdef", 'a', 0},
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRCHR - " RESET);
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
