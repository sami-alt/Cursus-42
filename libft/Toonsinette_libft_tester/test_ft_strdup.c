#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*src;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*expected = strdup(test->src);
	char	*actual = ft_strdup(test->src);

	if (actual && strcmp(expected, actual) == 0)
		test->passed = 1;
	else
		test->passed = 0;
	free(expected);
	free(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		{"Sweet evaluator.", 0},
		{"", 0},
		{"42", 0},
		{"Hive School for ever !", 0},
		{"Special chars: !@#$%^&*()", 0},
		{"\xFF\x00\x01", 0},
		{"The hiver builds test again, again and angain.", 0},
		{NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRDUP - " RESET);
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
