#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	char		*input;
	char		delimiter;
	char		**expected;
	int			passed;
}	t_test_result;

int	compare_results(char **actual, char **expected)
{
	int i = 0;

	while (actual[i] && expected[i])
	{
		if (strcmp(actual[i], expected[i]) != 0)
			return (0);
		i++;
	}
	if (actual[i] || expected[i])
		return (0);
	return (1);
}

void	free_split_array(char **split)
{
	int i = 0;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	run_test(t_test_result *test)
{
	char **actual = ft_split(test->input, test->delimiter);

	if (compare_results(actual, test->expected))
		test->passed = 1;
	else
		test->passed = 0;
	free_split_array(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		{"Hello,World", ',', (char *[]){"Hello", "World", NULL}, 0},
		{"   split this  string   ", ' ', (char *[]){"split", "this", "string", NULL}, 0},
		{"42 is fun", ' ', (char *[]){"42", "is", "fun", NULL}, 0},
		{"multiple,,,commas", ',', (char *[]){"multiple", "commas", NULL}, 0},
		{"no_delimiters_here", ',', (char *[]){"no_delimiters_here", NULL}, 0},
		{"", ',', (char *[]) {NULL}, 0},
		{",,,,,", ',', (char *[]) {NULL}, 0},
		{"split,with,multiple,words", ',', (char *[]){"split", "with", "multiple", "words", NULL}, 0},
		{"test with\nnewline", ' ', (char *[]){"test", "with\nnewline", NULL}, 0},
		{"   a   b  c ", ' ', (char *[]){"a", "b", "c", NULL}, 0},
		{NULL, 0, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_SPLIT - " RESET);
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
