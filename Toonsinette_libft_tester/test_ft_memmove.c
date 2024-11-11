#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_test_result
{
	char		buffer[100];
	size_t		src_offset;
	size_t		dest_offset;
	size_t		n;
	int			passed;
}	t_test_result;

void	run_test(t_test_result *test)
{
	char	expected_buffer[100];
	char	actual_buffer[100];

	memcpy(expected_buffer, test->buffer, sizeof(test->buffer));
	memcpy(actual_buffer, test->buffer, sizeof(test->buffer));
	memmove(expected_buffer + test->dest_offset, 
			expected_buffer + test->src_offset, 
			test->n);
	ft_memmove(actual_buffer + test->dest_offset, 
			actual_buffer + test->src_offset, 
			test->n);

	if (memcmp(expected_buffer, actual_buffer, sizeof(expected_buffer)) == 0)
		test->passed = 1;
	else
		test->passed = 0;
}

int	main(void)
{
	t_test_result tests[] = {
		// Basic copying (non-overlapping)
		{ .buffer = "Hello, World!", .src_offset = 0, .dest_offset = 0, .n = 8, .passed = 0 },
		{ .buffer = "Hello, World!", .src_offset = 0, .dest_offset = 7, .n = 2, .passed = 0 },
		{ .buffer = "Test", .src_offset = 0, .dest_offset = 0, .n = 5, .passed = 0 },

		// Copying partial data
		{ .buffer = "Buffer 1", .src_offset = 0, .dest_offset = 1, .n = 4, .passed = 0 },

		// Copying to the same destination
		{ .buffer = "Same source", .src_offset = 0, .dest_offset = 0, .n = 10, .passed = 0 },

		// Copy zero bytes
		{ .buffer = "No Change", .src_offset = 0, .dest_offset = 0, .n = 0, .passed = 0 },

		// Overlapping memory regions (forward overlap)
		{ .buffer = "OverlappingTest", .src_offset = 0, .dest_offset = 4, .n = 7, .passed = 0 },

		// Overlapping memory regions (backward overlap)
		{ .buffer = "OverlappingTest", .src_offset = 4, .dest_offset = 0, .n = 7, .passed = 0 },

		// Larger n values
		{ .buffer = "Large Copy", .src_offset = 0, .dest_offset = 0, .n = 20, .passed = 0 },

		// Empty buffers
		{ .buffer = "Existing\0", .src_offset = 8, .dest_offset = 0, .n = 1, .passed = 0 },
		{ .buffer = "\0Ginyu", .src_offset = 1, .dest_offset = 0, .n = 5, .passed = 0 },
		{ .buffer = "\0\0", .src_offset = 0, .dest_offset = 0, .n = 5, .passed = 0 },
		
		// Long string to short destination
		{ .buffer = "Short\0Longer String", .src_offset = 6, .dest_offset = 0, .n = 5, .passed = 0 },

		// Sentinel to mark end of tests
		{ .buffer = "", .src_offset = 0, .dest_offset = 0, .n = 0, .passed = 0 }
	};

	int	passed_tests = 0;
	int	failed_tests = 0;
	int	total_tests = sizeof(tests)/sizeof(tests[0]) - 1;

	printf(BLUE "FT_MEMMOVE - " RESET);
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
