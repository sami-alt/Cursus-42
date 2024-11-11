#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "libft.h"

typedef struct s_test_result
{
	size_t		nmemb;
	size_t		size;
	int			should_fail;
	int			passed;
}	t_test_result;

int	is_memory_zeroed(void *ptr, size_t size)
{
	unsigned char *byte_ptr = (unsigned char *)ptr;
	for (size_t i = 0; i < size; i++)
	{
		if (byte_ptr[i] != 0)
			return (0);
	}
	return (1);
}

void	run_test(t_test_result *test)
{
	void	*ptr;

	ptr = ft_calloc(test->nmemb, test->size);
	if (test->should_fail)
	{
		test->passed = (ptr == NULL);
		return;
	}
	if (ptr == NULL)
	{
		test->passed = 0;
		return;
	}
	test->passed = is_memory_zeroed(ptr, test->nmemb * test->size);
	free(ptr);
}


int	main(void)
{
	t_test_result	tests[] = {
		// 1. nmemb=0, size=0
		{0, 0, 0, 0},
		// 2. nmemb=1, size=1
		{1, 1, 0, 0},
		// 3. nmemb=2, size=3
		{2, 3, 0, 0},
		// 4. nmemb=100, size=0
		{100, 0, 0, 0},
		// 5. nmemb=0, size=100
		{0, 100, 0, 0},
		// 6. nmemb=100, size=4
		{100, 4, 0, 0},
		// 7. nmemb=10, size=10
		{10, 10, 0, 0},
		// 8. nmemb=50, size=20
		{50, 20, 0, 0},
		// 9. Overflow
		{SIZE_MAX, 2, 1, 0},
		// 10. Large allocation
		{1000, 1000, 0, 0},
		{0, 0, 0, -1}
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	i = 0;

	printf(BLUE "FT_CALLOC - " RESET);
	while (tests[i].passed != -1)
	{
		run_test(&tests[i]);
		if (tests[i].passed)
			passed_tests++;
		else
			failed_tests++;
		i++;
	}
	printf("Total Tests: %d -> ", passed_tests + failed_tests);
	printf(GREEN " %d✅\n" RESET, passed_tests);
	if (failed_tests > 0)
		printf(RED " %d❌\n" RESET, failed_tests);

	return (failed_tests == 0) ? 0 : 1;
}
