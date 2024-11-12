#include <stdio.h>
#include <string.h>
#include "libft.h"

void	increment_by_index(unsigned int i, char *c)
{
	*c += i;
}

void	to_uppercase(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

typedef struct s_test_result
{
	char		*input;
	void		(*f)(unsigned int, char*);
	char		*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = strdup(test->input);

	ft_striteri(actual, test->f);
	if (strcmp(actual, test->expected) == 0)
		test->passed = 1;
	else
		test->passed = 0;
	free(actual);
}

int	main(void)
{
	t_test_result	tests[] = {
		{"abc", increment_by_index, "ace", 0},
		{"12345", increment_by_index, "13579", 0},
		{"hello", to_uppercase, "HELLO", 0},
		{"42", to_uppercase, "42", 0},
		{"", to_uppercase, "", 0},
		{"lowerCASE", to_uppercase, "LOWERCASE", 0},
		{NULL, NULL, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_STRITERI - " RESET);
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
