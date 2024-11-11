#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct s_test_result
{
	unsigned char	input[50];
	size_t			n;
	unsigned char	expected[50];
	int				passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	ft_bzero(test->input, test->n);
	test->passed = (memcmp(test->input, test->expected, sizeof(test->input)) == 0) ? 1 : 0;
}

int	main(void)
{
	t_test_result	tests[] = {
		// 1. Zeroing zero bytes should not change the buffer
		{
			.input = { 'A', 'B', 'C', 'D', 'E', 0 },
			.n = 0,
			.expected = { 'A', 'B', 'C', 'D', 'E', 0 },
			.passed = 0
		},
		// 2. Zeroing first byte
		{
			.input = { 'A', 'B', 'C', 'D', 'E', 0 },
			.n = 1,
			.expected = { 0, 'B', 'C', 'D', 'E', 0 },
			.passed = 0
		},
		// 3. Zeroing first three bytes
		{
			.input = { 'A', 'B', 'C', 'D', 'E', 0 },
			.n = 3,
			.expected = { 0, 0, 0, 'D', 'E', 0 },
			.passed = 0
		},
		// 4. Zeroing entire buffer
		{
			.input = { 'H', 'e', 'l', 'l', 'o', 0 },
			.n = 6,
			.expected = { 0, 0, 0, 0, 0, 0 },
			.passed = 0
		},
		// 5.
		{
			.input = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0 },
			.n = 12,
			.expected = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			.passed = 0
		},
		// 6. Zeroing part of buffer with mixed data
		{
			.input = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 },
			.n = 5,
			.expected = { 0, 0, 0, 0, 0, '6', '7', '8', '9', 0 },
			.passed = 0
		},
		// 7. Zeroing with n greater than buffer size
		{
			.input = { 'X', 'Y', 'Z', 0 },
			.n = 10,
			.expected = { 0, 0, 0, 0 },
			.passed = 0
		},
		// 8. Zeroing an empty buffer
		{
			.input = { 0 },
			.n = 0,
			.expected = { 0 },
			.passed = 0
		},
		// 9. Zeroing buffer with multiple zeros
		{
			.input = { 0, 0, 'A', 'B', 0 },
			.n = 2,
			.expected = { 0, 0, 'A', 'B', 0 },
			.passed = 0
		},
		// 10. Zeroing after leading zero bytes
		{
			.input = { 0, 0, 'A', 'B', 'C', 0 },
			.n = 3,
			.expected = { 0, 0, 0, 'B', 'C', 0 },
			.passed = 0
		},
		{ {0}, 0, {0}, 0 }
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	i = 0;
	int num_tests = sizeof(tests) / sizeof(tests[0]) - 1;

	printf(BLUE "FT_BZERO - " RESET);
	while (i < num_tests)
	{
		run_test(&tests[i]);
		if (tests[i].passed)
			passed_tests++;
		else
		{
			failed_tests++;
			printf("Test %d failed.\n", i + 1);
		}
		i++;
	}
	printf("Total Tests: %d -> ", passed_tests + failed_tests);
	printf(GREEN " %d✅" RESET, passed_tests);
	if (failed_tests > 0)
		printf(RED " %d❌" RESET, failed_tests);
	printf("\n");
	return (failed_tests == 0) ? 0 : 1;
}
