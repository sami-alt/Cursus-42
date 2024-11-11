/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:30:00 by nlouis            #+#    #+#             */
/*   Updated: 2024/10/31 13:49:45 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*str;
	int			c;
	const char	*expected;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	*actual = ft_strrchr(test->str, test->c);
	if (actual == test->expected || (actual && strcmp(actual, test->expected) == 0))
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// Case 1: Last occurrence of a character in the middle
		{"Hello, World!", 'o', "orld!", 0},
		// Case 2: Last occurrence of a character at the end
		{"Hello, World!", '!', "!", 0},
		// Case 3: Character not present in the string
		{"Hello, World!", 'x', NULL, 0},
		// Case 4: Searching for the null terminator (should return pointer to '\0')
		{"Hello, World!", '\0', "", 0},
		// Case 5: Empty string, searching for '\0' (should return pointer to '\0')
		{"", '\0', "", 0},
		// Case 6: Empty string, searching for any character (should return NULL)
		{"", 'a', NULL, 0},
		// Case 7: String with repeated characters, searching for 'l'
		{"balloon", 'l', "loon", 0},
		// Case 8: String with spaces
		{"This is a test string", ' ', " string", 0},
		// Case 9: Searching for a character not present in the string
		{"abcdef", 'z', NULL, 0},
		{NULL, 0, NULL, 0}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests) / sizeof(tests[0]) - 1;
	
	printf(BLUE "FT_STRRCHR - " RESET);
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
