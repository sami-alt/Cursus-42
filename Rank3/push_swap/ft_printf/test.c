#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

void ft_test_for_char(void)
{
	int printf_return = 0;
	int ft_printf_return = 0;

	printf("---- Test cases for flag 'c' : -----\n");

	printf(" 01. Lower case character : 't' \n");
	printf("      standard : ");
	printf_return = printf("%c", 't');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", 't');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 02. Upper case character : 'T' \n");
	printf("      standard : ");
	printf_return = printf("%c", 'T');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", 'T');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 03. Null character : '\\0' \n");
	printf("      standard : ");
	printf_return = printf("%c", '\0');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", '\0');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 04. Out of range ASCII value : '300' \n");
	printf("      standard : ");
	printf_return = printf("%c", 300);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", 300);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. Negative ASCII value : '-1' \n");
	printf("      standard : ");
	printf_return = printf("%c",-1);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", -1);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. Non printbale character : '\\t' \n");
	printf("      standard : ");
	printf_return = printf("%c",'\t');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", '\t');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. No corresponding argument : '' \n");
	printf("      standard : ");
	printf_return = printf("%c");
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c");
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. Wide character : L'あ' \n");
	printf("      standard : ");
	printf_return = printf("%c", L'あ');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", L'あ');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 09. Mismatch argument : '3.14' \n");
	printf("      standard : ");
	printf_return = printf("%c", 3.14);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", 3.14);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Multiple arguments : 'A B C ' \n");
	printf("      standard : ");
	printf_return = printf("%c", 'A', 'B', 'C');
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%c", 'A', 'B', 'C');
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Mimic an error : 'A' \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%c", 'A');
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%c", 'A');
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);

}

void ft_test_for_string(void)
{
	int printf_return = 0;
	int ft_printf_return = 0;
	char *str1 = "Hive Helsinki ";
	char *str2 = "is awsome ";
	char *str3 = "place to learn coding";

	printf("---- Test cases for flag 's' : -----\n");

	printf(" 01. Regular string using double quotaion : \"Hive Helsinki \"\n");
	printf("      standard : ");
	printf_return = printf("%s", "Hive Helsinki!");
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", "Hive Helsinki!");
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 02. Regular string using char pointer : char *str = \"Hive Helsinki \"\n");
	printf("      standard : ");
	printf_return = printf("%s", str1);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str1);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 03. Mulitiple char pointers : str1, str2, str3 \n");
	printf("      standard : ");
	printf_return = printf("%s%s%s", str1, str2, str3);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s%s%s", str1, str2, str3);
	printf("\n        - return value : %d \n", ft_printf_return);

	str1 = NULL;

	printf(" 04. Null pointer : str1 = NULL \n");
	printf("      standard : ");
	printf_return = printf("%s", str1);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str1);
	printf("\n        - return value : %d \n", ft_printf_return);

	str1 = "";

	printf(" 05. Empty string : str1 = \"\" \n");
	printf("      standard : ");
	printf_return = printf("%s", str1);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str1);
	printf("\n        - return value : %d \n", ft_printf_return);

	char str[5] = {'H','e','l','l','o'};

	printf(" 06. String with out null terminator : char str[5] = {'H','e','l','l','o'} \n");
	printf("      standard : ");
	printf_return = printf("%s", str);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str);
	printf("\n        - return value : %d \n", ft_printf_return);

	wchar_t *wstr = L"Hello";

	printf(" 07. Wide charaters : L\"Hello\" \n");
	printf("      standard : ");
	printf_return = printf("%s", wstr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", wstr);
	printf("\n        - return value : %d \n", ft_printf_return);

	str1 = "Hello";

	printf(" 08. Character pointer arithmatics : str + 2 \n");
	printf("      standard : ");
	printf_return = printf("%s", str + 2);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str + 2);
	printf("\n        - return value : %d \n", ft_printf_return);

	// char str_lrg[100000];
	// memset(str_lrg, 'A', 99998);
	// str_lrg[99999] = '\0';

	// printf(" 09. Very large string : str_lrg[99999] \n");
	// printf("      standard : ");
	// printf_return = printf("%s", str_lrg);
	// printf("\n        - return value : %d \n", printf_return);
	// printf("      custome  : ");
	// fflush(stdout);
	// ft_printf_return = ft_printf("%s", str_lrg);
	// printf("\n        - return value : %d \n", ft_printf_return);

	char str_ptr[6] = {'H','e','l','\t','l','o'};

	printf(" 10. Non printable character in the middle of the string : char str_ptr[6] = {'H','e','l','\\t','l','o'} \n");
	printf("      standard : ");
	printf_return = printf("%s", str_ptr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str_ptr);
	printf("\n        - return value : %d \n", ft_printf_return);

	char str_nll[6] = {'H','e','l','\0','l','o'};

	printf(" 11. Null byte in the middle of the string : char str_ptr[6] = {'H','e','l','\\0','l','o'} \n");
	printf("      standard : ");
	printf_return = printf("%s", str_nll);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", str_nll);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. No corresponding argument :  \n");
	printf("      standard : ");
	printf_return = printf("%s");
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s");
	printf("\n        - return value : %d \n", ft_printf_return);

	char *arr[] = {"Hello", NULL, "World"};

	printf(" 13. Embedded NULL pointers : char *arr[] = {\"Hello\", NULL, \"World\"} \n");
	printf("      standard : ");
	printf_return = printf("%s", arr[1]);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s",arr[1]);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 14. Mismatch arguments :  \n");
	printf("      standard : ");
	printf_return = printf("%s", 3.14);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%s", 3.14);
	printf("\n        - return value : %d \n", ft_printf_return);


	printf(" 15. Mimic an error : \"Hello\" \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%s", "Hello");
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custome  : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%s", "Hello");
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);

}

void ft_test_for_pointer(void)
{
	int printf_return = 0;
	int ft_printf_return = 0;
	int x = 42;
	int *ptr = &x;
	int *null_ptr = NULL;
	void (*func_ptr)() = (void (*)())printf;

	printf("---- Test cases for flag 'p' : -----\n");

	printf(" 01. Regular pointer to a variable: int *ptr = &x\n");
	printf("      standard : ");
	printf_return = printf("%p", ptr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", ptr);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 02. Null pointer: int *null_ptr = NULL\n");
	printf("      standard : ");
	printf_return = printf("%p", null_ptr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", null_ptr);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 03. Pointer arithmetic: ptr + 1\n");
	printf("      standard : ");
	printf_return = printf("%p", ptr + 1);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", ptr + 1);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 04. Function pointer: void (*func_ptr)() = printf\n");
	printf("      standard : ");
	printf_return = printf("%p", func_ptr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", func_ptr);
	printf("\n        - return value : %d \n", ft_printf_return);


	int *uninitialized_ptr;
	printf(" 05. Uninitialized pointer: int *uninitialized_ptr\n");
	printf("      standard : ");
	printf_return = printf("%p", uninitialized_ptr);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", uninitialized_ptr);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. Cast integer to pointer: (void *)12345\n");
	printf("      standard : ");
	printf_return = printf("%p", (void *)12345);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", (void *)12345);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. Null pointer cast to void*: (void *)NULL\n");
	printf("      standard : ");
	printf_return = printf("%p", (void *)NULL);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", (void *)NULL);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. Mismatched arguments: printf(\"%%p\", 42)\n");
	printf("      standard : ");
	printf_return = printf("%p", 42);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", 42);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 09. Embedded NULL pointer: int *arr[] = {ptr, NULL}\n");
	int *arr[] = {ptr, NULL};
	printf("      standard : ");
	printf_return = printf("%p", arr[1]);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", arr[1]);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Special pointer: (void *)0\n");
	printf("      standard : ");
	printf_return = printf("%p", (void *)0);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", (void *)0);
	printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. dynamically allocated pointer: malloc(1 * sizeof(int))\n");
	int *ptrd = malloc(1 * sizeof(int));
	printf("      standard : ");
	printf_return = printf("%p", ptrd);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p", ptrd);
	printf("\n        - return value : %d \n", ft_printf_return);
	free(ptrd);

	printf(" 12. No corresponding argument: \n");
	printf("      standard : ");
	printf_return = printf("%p");
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	ft_printf_return = ft_printf("%p");
	printf("\n        - return value : %d \n", ft_printf_return);


	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%p", ptr);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%p", ptr);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_hex_lowercase(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag 'x' : -----\n");

    printf(" 01. Regular positive integer: 255\n");
    printf("      standard : ");
    printf_return = printf("%x", 255);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 255);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. Zero: 0\n");
    printf("      standard : ");
    printf_return = printf("%x", 0);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Large positive integer: 4294967295\n");
    printf("      standard : ");
    printf_return = printf("%x", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Negative integer: -255\n");
    printf("      standard : ");
    printf_return = printf("%x", -255);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", -255);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. INT_MAX: 2147483647\n");
    printf("      standard : ");
    printf_return = printf("%x", INT_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", INT_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. INT_MIN: -2147483648\n");
    printf("      standard : ");
    printf_return = printf("%x", INT_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", INT_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. ULLONGMAX: 18446744073709551615\n");
    printf("      standard : ");
    printf_return = printf("%x", ULLONG_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", ULLONG_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. LLONGMIN: -9223372036854775807\n");
    printf("      standard : ");
    printf_return = printf("%x", LLONG_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", LLONG_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 09. No corresponding argument : \n");
    printf("      standard : ");
    printf_return = printf("%x");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Hexa decimal value in lower case : \n");
    printf("      standard : ");
    printf_return = printf("%x", 0x1e240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 0x1e240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Hexa decimal value in upper case : \n");
    printf("      standard : ");
    printf_return = printf("%x", 0x1E240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 0x1E240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. Mismatch argument: \n");
    printf("      standard : ");
    printf_return = printf("%x", 3.14);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%x", 3.14);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%x", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%x", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_hex_uppercase(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag 'X' : -----\n");

    printf(" 01. Regular positive integer: 255\n");
    printf("      standard : ");
    printf_return = printf("%X", 255);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 255);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. Zero: 0\n");
    printf("      standard : ");
    printf_return = printf("%X", 0);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Large positive integer: 4294967295\n");
    printf("      standard : ");
    printf_return = printf("%X", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Negative integer: -255\n");
    printf("      standard : ");
    printf_return = printf("%X", -255);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", -255);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. INT_MAX: 2147483647\n");
    printf("      standard : ");
    printf_return = printf("%X", INT_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", INT_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. INT_MIN: -2147483648\n");
    printf("      standard : ");
    printf_return = printf("%X", INT_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", INT_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. ULLONGMAX: 18446744073709551615\n");
    printf("      standard : ");
    printf_return = printf("%X", ULLONG_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", ULLONG_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. LLONGMIN: -9223372036854775807\n");
    printf("      standard : ");
    printf_return = printf("%X", LLONG_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", LLONG_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 09. No corresponding argument : \n");
    printf("      standard : ");
    printf_return = printf("%X");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Hexa decimal value in lower case : \n");
    printf("      standard : ");
    printf_return = printf("%X", 0x1e240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 0x1e240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Hexa decimal value in upper case : \n");
    printf("      standard : ");
    printf_return = printf("%X", 0x1E240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 0x1E240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. Mismatch argument: \n");
    printf("      standard : ");
    printf_return = printf("%X", 3.14);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%X", 3.14);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%X", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%X", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_integers(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag 'i' : -----\n");

    printf(" 01. Regular positive integer: 42\n");
    printf("      standard : ");
    printf_return = printf("%i", 42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 42);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. Zero: 0\n");
    printf("      standard : ");
    printf_return = printf("%i", 0);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Large positive integer: 4294967295\n");
    printf("      standard : ");
    printf_return = printf("%i", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Negative integer: -42\n");
    printf("      standard : ");
    printf_return = printf("%i", -42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", -42);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. INT_MAX: 2147483647\n");
    printf("      standard : ");
    printf_return = printf("%i", INT_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", INT_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. INT_MIN: -2147483648\n");
    printf("      standard : ");
    printf_return = printf("%i", INT_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", INT_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. ULLONGMAX: 18446744073709551615\n");
    printf("      standard : ");
    printf_return = printf("%i", ULLONG_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", ULLONG_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. LLONGMIN: -9223372036854775807\n");
    printf("      standard : ");
    printf_return = printf("%i", LLONG_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", LLONG_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 09. No corresponding argument : \n");
    printf("      standard : ");
    printf_return = printf("%i");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Hexa decimal value in lower case : \n");
    printf("      standard : ");
    printf_return = printf("%i", 0x1e240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 0x1e240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Hexa decimal value in upper case : \n");
    printf("      standard : ");
    printf_return = printf("%i", 0x1E240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 0x1E240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. Mismatch argument: \n");
    printf("      standard : ");
    printf_return = printf("%i", 3.14);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%i", 3.14);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%i", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%i", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_decimal(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag 'd' : -----\n");

    printf(" 01. Regular positive integer: 42\n");
    printf("      standard : ");
    printf_return = printf("%d", 42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 42);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. Zero: 0\n");
    printf("      standard : ");
    printf_return = printf("%d", 0);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Large positive integer: 4294967295\n");
    printf("      standard : ");
    printf_return = printf("%d", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Negative integer: -42\n");
    printf("      standard : ");
    printf_return = printf("%d", -42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", -42);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. INT_MAX: 2147483647\n");
    printf("      standard : ");
    printf_return = printf("%d", INT_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", INT_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. INT_MIN: -2147483648\n");
    printf("      standard : ");
    printf_return = printf("%d", INT_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", INT_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. ULLONGMAX: 18446744073709551615\n");
    printf("      standard : ");
    printf_return = printf("%d", ULLONG_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", ULLONG_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. LLONGMIN: -9223372036854775807\n");
    printf("      standard : ");
    printf_return = printf("%d", LLONG_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", LLONG_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 09. No corresponding argument : \n");
    printf("      standard : ");
    printf_return = printf("%d");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Hexa decimal value in lower case : 0x1e240\n");
    printf("      standard : ");
    printf_return = printf("%d", 0x1e240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 0x1e240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Hexa decimal value in upper case : 0x1E240\n");
    printf("      standard : ");
    printf_return = printf("%d", 0x1E240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 0x1E240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. Mismatch argument: 3.14\n");
    printf("      standard : ");
    printf_return = printf("%d", 3.14);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%d", 3.14);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%d", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%d", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_unsinged(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag 'u' : -----\n");

    printf(" 01. Regular positive integer: 42\n");
    printf("      standard : ");
    printf_return = printf("%u", 42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 42);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. Zero: 0\n");
    printf("      standard : ");
    printf_return = printf("%u", 0);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Large positive integer: 4294967295\n");
    printf("      standard : ");
    printf_return = printf("%u", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Negative integer: -42\n");
    printf("      standard : ");
    printf_return = printf("%u", -42);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", -42);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. INT_MAX: 2147483647\n");
    printf("      standard : ");
    printf_return = printf("%u", INT_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", INT_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. INT_MIN: -2147483648\n");
    printf("      standard : ");
    printf_return = printf("%u", INT_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", INT_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. ULLONGMAX: 18446744073709551615\n");
    printf("      standard : ");
    printf_return = printf("%u", ULLONG_MAX);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", ULLONG_MAX);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 08. LLONGMIN: -9223372036854775807\n");
    printf("      standard : ");
    printf_return = printf("%u", LLONG_MIN);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", LLONG_MIN);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 09. No corresponding argument : \n");
    printf("      standard : ");
    printf_return = printf("%u");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 10. Hexa decimal value in lower case : 0x1e240\n");
    printf("      standard : ");
    printf_return = printf("%u", 0x1e240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 0x1e240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 11. Hexa decimal value in upper case : 0x1E240\n");
    printf("      standard : ");
    printf_return = printf("%u", 0x1E240);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 0x1E240);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 12. Mismatch argument: 3.14\n");
    printf("      standard : ");
    printf_return = printf("%u", 3.14);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%u", 3.14);
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 13. Mimic an error: \n");
	printf("      standard : ");
	fclose(stdout);
	printf_return = printf("%u", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", printf_return);
	printf("      custom   : ");
	fflush(stdout);
	fclose(stdout);
	ft_printf_return = ft_printf("%u", 255);
	freopen("/dev/tty", "w", stdout);
	printf("\n        - return value : %d \n", ft_printf_return);
}

void ft_test_for_percentage(void)
{
    int printf_return = 0;
    int ft_printf_return = 0;

    printf("---- Test cases for flag '%c' : -----\n", '%');

    printf(" 01. %c character ending with null byte\n", '%');
    printf("      standard : ");
    printf_return = printf("%");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%");
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 02. two %c characters\n",'%');
    printf("      standard : ");
    printf_return = printf("%%");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%%", 0);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 03. Three or more %c characters\n",'%');
    printf("      standard : ");
    printf_return = printf("%%%", 4294967295U);
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%%%", 4294967295U);
    printf("\n        - return value : %d \n", ft_printf_return);

    printf(" 04. Two %c characters with space in between\n", '%');
    printf("      standard : ");
    printf_return = printf("% %");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("% %");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 05. %c character followed by some regular characters\n",'%');
    printf("      standard : ");
    printf_return = printf("%jhelp");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%jhelp");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 06. Invalid flag : %ck\n", '%');
    printf("      standard : ");
    printf_return = printf("%k");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%k");
    printf("\n        - return value : %d \n", ft_printf_return);

	printf(" 07. Invalid flag followed by regular characters\n");
    printf("      standard : ");
    printf_return = printf("%k help");
    printf("\n        - return value : %d \n", printf_return);
    printf("      custom   : ");
    fflush(stdout);
    ft_printf_return = ft_printf("%k help");
    printf("\n        - return value : %d \n", ft_printf_return);
}

int main(void)
{
	// ft_test_for_char();
	// ft_test_for_string();
	// ft_test_for_pointer();
	// ft_test_for_hex_lowercase();
	// ft_test_for_hex_uppercase();
	// ft_test_for_integers();
	// ft_test_for_decimal();
	// ft_test_for_unsinged();
	ft_test_for_percentage();
	return (0);
}