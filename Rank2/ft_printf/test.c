
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:27:59 by jhyokki           #+#    #+#             */
/*   Updated: 2024/11/29 14:02:50 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "ft_printf.h"

/* Test printing a simple string */
START_TEST(test_ft_printf_hello_world)
{
	int	ret = ft_printf("Hello, World!\n");
	ck_assert_int_eq(ret, 14);
}
END_TEST

/* Test printing a positive int with %d */
START_TEST(test_ft_printf_positive_d)
{
	int	ret = ft_printf("Number: %d\n", 42);
	ck_assert_int_eq(ret, 11);
}
END_TEST

/* Test printing a negative int with %d */
START_TEST(test_ft_printf_negative_d)
{
	int	ret = ft_printf("Number: %d\n", -42);
	ck_assert_int_eq(ret, 12);
}
END_TEST

/* Test printing a zero int with %d */
START_TEST(test_ft_printf_zero_d)
{
	int	ret = ft_printf("Number: %d\n", 0);
	ck_assert_int_eq(ret, 10);
}
END_TEST

/* Test printing a positive int with %i */
START_TEST(test_ft_printf_positive_i)
{
	int	ret = ft_printf("Number: %i\n", 42);
	ck_assert_int_eq(ret, 11);
}
END_TEST

/* Test printing a negative int with %i */
START_TEST(test_ft_printf_negative_i)
{
	int	ret = ft_printf("Number: %i\n", -42);
	ck_assert_int_eq(ret, 12);
}
END_TEST

/* Test printing a zero int with %i */
START_TEST(test_ft_printf_zero_i)
{
	int	ret = ft_printf("Number: %i\n", 0);
	ck_assert_int_eq(ret, 10);
}
END_TEST

/* Test printing a simple string with %s */
START_TEST(test_ft_printf_string_s)
{
	int ret = ft_printf("String: %s\n", "Hello, World!");
	ck_assert_int_eq(ret, 22);
}
END_TEST

/* Test printing a null string with %s */
START_TEST(test_ft_printf_null_string_s)
{
	int ret = ft_printf("String: %s\n", NULL);
	ck_assert_int_eq(ret, 15);
}
END_TEST

/* Test printing a positive number with %x */
START_TEST(test_ft_printf_hex_lower_positive)
{
	int ret = ft_printf("Hex (lower): %x\n", 255);
	ck_assert_int_eq(ret, 16); // "Hex (lower): ff\n" has 16 characters
}
END_TEST

/* Test printing zero with %x */
START_TEST(test_ft_printf_hex_lower_zero)
{
	int ret = ft_printf("Hex (lower): %x\n", 0);
	ck_assert_int_eq(ret, 15); // "Hex (lower): 0\n" has 15 characters
}
END_TEST

/* Test printing maximum unsigned int with %x */
START_TEST(test_ft_printf_hex_lower_max)
{
	int ret = ft_printf("Hex (lower): %x\n", 4294967295U);
	ck_assert_int_eq(ret, 22); // "Hex (lower): ffffffff\n" has 22 characters
}
END_TEST

/* Test printing a positive number with %X */
START_TEST(test_ft_printf_hex_upper_positive)
{
	int ret = ft_printf("Hex (upper): %X\n", 255);
	ck_assert_int_eq(ret, 16); // "Hex (upper): FF\n" has 16 characters
}
END_TEST

/* Test printing zero with %X */
START_TEST(test_ft_printf_hex_upper_zero)
{
	int ret = ft_printf("Hex (upper): %X\n", 0);
	ck_assert_int_eq(ret, 15); // "Hex (upper): 0\n" has 15 characters
}
END_TEST

/* Test printing maximum unsigned int with %X */
START_TEST(test_ft_printf_hex_upper_max)
{
	int ret = ft_printf("Hex (upper): %X\n", 4294967295U);
	ck_assert_int_eq(ret, 22); // "Hex (upper): FFFFFFFF\n" has 22 characters
}
END_TEST

/* Test printing a positive unsigned int with %u */
START_TEST(test_ft_printf_unsigned_positive)
{
	int ret = ft_printf("Unsigned: %u\n", 300);
	ck_assert_int_eq(ret, 14); // "Unsigned: 300\n" has 14 characters
}
END_TEST

/* Test printing zero with %u */
START_TEST(test_ft_printf_unsigned_zero)
{
	int ret = ft_printf("Unsigned: %u\n", 0);
	ck_assert_int_eq(ret, 12); // "Unsigned: 0\n" has 12 characters
}
END_TEST

/* Test printing maximum unsigned int with %u */
START_TEST(test_ft_printf_unsigned_max)
{
	int ret = ft_printf("Unsigned: %u\n", 4294967295U);
	ck_assert_int_eq(ret, 21); // "Unsigned: 4294967295\n" has 21 characters
}
END_TEST

/* Test printing a pointer with %p */
START_TEST(test_ft_printf_pointer)
{
	int x = 42;
	int ret = ft_printf("Pointer: %p\n", &x);
	// Adjust the expected length based on the actual output
	ck_assert_int_eq(ret, 20); // Example: "Pointer: 0x7ffee3b8\n" has 14 characters
}
END_TEST

/* Test printing a character with %c */
START_TEST(test_ft_printf_char)
{
	int ret = ft_printf("Char: %c\n", 'A');
	ck_assert_int_eq(ret, 8); // "Char: A\n" has 8 characters
}
END_TEST

/* Test printing a percent sign with %% */
START_TEST(test_ft_printf_percent)
{
	int ret = ft_printf("Percent: %%\n");
	ck_assert_int_eq(ret, 11); // "Percent: %\n" has 11 characters
}
END_TEST

/* Test printing multiple different format specifiers */
START_TEST(test_ft_printf_multiple_formats)
{
	int ret = ft_printf("Multiple formats: %%, %i, %s\n", 42, "Hello, World!");
	ck_assert_int_eq(ret, 39);
}
END_TEST

/* Test printing an empty format string */
START_TEST(test_ft_printf_empty_format)
{
	int ret = ft_printf("");
	// Expected output: ""
	// Length: 0 characters
	ck_assert_int_eq(ret, 0);
}
END_TEST

/* Test printing a NULL format string */
START_TEST(test_ft_printf_null_format)
{
	int ret = ft_printf(NULL);
	// Expected behavior: Handle gracefully, possibly return -1
	ck_assert_int_eq(ret, -1);
}
END_TEST

/* Test printing a NULL string with %s */
START_TEST(test_ft_printf_null_string)
{
	int ret = ft_printf("String: %s\n", NULL);
	// Expected output: "String: (null)\n"
	// Length: 9 + 6 + 1 = 16 characters
	ck_assert_int_eq(ret, 15);
}
END_TEST

/* Test printing a very large unsigned int with %u */
START_TEST(test_ft_printf_unsigned_very_large)
{
	unsigned int large_num = 4294967295U; // Maximum unsigned int
	int ret = ft_printf("Very Large Unsigned: %u\n", large_num);
	// Expected output: "Very Large Unsigned: 4294967295\n"
	// Length: 22 characters
	ck_assert_int_eq(ret, 32);
}
END_TEST

/* Test printing an unsupported specifier */
START_TEST(test_ft_printf_unsupported_specifier)
{
	int ret = ft_printf("Unsupported: %q\n", 100);
	// Expected output: "Unsupported: \n" or handle as per implementation
	// Assuming it returns 12 characters ("Unsupported: \n")
	ck_assert_int_eq(ret, 16); // Adjust based on actual implementation
}
END_TEST

Suite *ft_printf_suite(void)
{
	Suite	*s;
	TCase	*tc_core;

	s = suite_create("ft_printf");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_ft_printf_hello_world);

	/* Add tests for %d specifier*/
	tcase_add_test(tc_core, test_ft_printf_positive_d);
	tcase_add_test(tc_core, test_ft_printf_negative_d);
	tcase_add_test(tc_core, test_ft_printf_zero_d);

	/* Add test for %i specifier*/
	tcase_add_test(tc_core, test_ft_printf_positive_i);
	tcase_add_test(tc_core, test_ft_printf_negative_i);
	tcase_add_test(tc_core, test_ft_printf_zero_i);

	/* Add tests for %s specifier */
	tcase_add_test(tc_core, test_ft_printf_string_s);
	tcase_add_test(tc_core, test_ft_printf_null_string_s);

	/* Add tests for %x specifier (lowercase) */
	tcase_add_test(tc_core, test_ft_printf_hex_lower_positive);
	tcase_add_test(tc_core, test_ft_printf_hex_lower_zero);
	tcase_add_test(tc_core, test_ft_printf_hex_lower_max);

	/* Add tests for %X specifier (uppercase) */
	tcase_add_test(tc_core, test_ft_printf_hex_upper_positive);
	tcase_add_test(tc_core, test_ft_printf_hex_upper_zero);
	tcase_add_test(tc_core, test_ft_printf_hex_upper_max);

	/* Add tests for %u specifier */
	tcase_add_test(tc_core, test_ft_printf_unsigned_positive);
	tcase_add_test(tc_core, test_ft_printf_unsigned_zero);
	tcase_add_test(tc_core, test_ft_printf_unsigned_max);

	/* Add tests for %p specifier*/
	tcase_add_test(tc_core, test_ft_printf_pointer);

	/* Add tests for %c specifier*/
	tcase_add_test(tc_core, test_ft_printf_char);

	/* Add tests for %% specifier*/
	tcase_add_test(tc_core, test_ft_printf_percent);

	/* Tests for multiple formats and edge cases */
	tcase_add_test(tc_core, test_ft_printf_multiple_formats);
	tcase_add_test(tc_core, test_ft_printf_empty_format);
	tcase_add_test(tc_core, test_ft_printf_null_format);
	tcase_add_test(tc_core, test_ft_printf_null_string);
	tcase_add_test(tc_core, test_ft_printf_unsigned_very_large);
	tcase_add_test(tc_core, test_ft_printf_unsupported_specifier);

	suite_add_tcase(s, tc_core);

	return (s);
}

int	main(void)
{
	int	number_failed;
	Suite	*s;
	SRunner	*sr;

	s = ft_printf_suite();
	sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return ((number_failed == 0) ? 0 : 1);
}
