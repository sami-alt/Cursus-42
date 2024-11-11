#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"

typedef struct s_test_result
{
	const char	*input;
	int			expected;
	int			actual;
	int			passed;
}				t_test_result;

static void	run_test(const char *input, t_test_result *result)
{
	result->input = input;
	result->expected = atoi(input);
	result->actual = ft_atoi(input);
	result->passed = (result->expected == result->actual) ? 1 : 0;
}

int	main(void)
{
	const char *tests[] = {
		// 1. Basic Conversion
		"0",
		"42",
		"-42",
		"+42",
		// 2. Leading Whitespace
		"   123",
		"\t\n\r\v\f456",
		" \t -789",
		// 3. Sign Handling
		"+",
		"-"
		"-0",
		"+0",
		"-2147483648", // INT_MIN
		"2147483647",  // INT_MAX
		// 4. Non-Digit Characters
		"123abc",
		"   -42xyz",
		"4193 with words",
		"words and 987",
		// 5. Empty String
		"",
		// 6. Overflow and Underflow
		"2147483648",  // INT_MAX + 1
		"-2147483649", // INT_MIN - 1
		// 7. Mixed Content
		"   +0 123",
		"+-2",
		"  -0012a42",
		// 8. Multiple leading zeroes
		"0000000123",
		"  -000254",
		"\t+000254",
		// 9. Large number within range
		"2147483646",
		"2000005445",
		"-2000005445",
		// 10. Negative zero
		"-0",
		// 11. Overflow
		"9223372036854775807", // LLONG_MAX
		"-9223372036854775808",// LLONG_MIN
		"18446744073709551615",// ULLONG_MAX
		NULL
    };

	t_test_result result;
	int passed_tests = 0;
	int failed_tests = 0;
	int i = 0;

	printf(BLUE "FT_ATOI - " RESET);
	while (tests[i] != NULL)
	{
		run_test(tests[i++], &result);
		(result.passed) ? passed_tests++ : failed_tests++;
	}
	printf("Total Tests: %d -> ", passed_tests + failed_tests);
	printf(GREEN " %d✅\n" RESET, passed_tests);
	if (failed_tests > 0)
		printf(RED " %d❌\n" RESET, failed_tests);
	return (failed_tests == 0) ? 0 : 1;
}

