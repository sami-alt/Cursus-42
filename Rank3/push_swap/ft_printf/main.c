#include "ft_printf.h"
#include <assert.h>
#include <stdio.h>

int main()
{	
	int adr = 1;


	assert(printf("Hello\n") == ft_printf("Hello\n"));
	assert(printf("%c\n", 'a') == ft_printf("%c\n", 'a'));
	assert(printf("%s\n", "Hello") == ft_printf("%s\n", "Hello"));
	assert(printf("") == ft_printf(""));
	assert(printf(NULL) == ft_printf(NULL));
	
	assert(printf("%p\n", &adr) == ft_printf("%p\n", &adr));

	assert(printf("%d\n", 5) == ft_printf("%d\n", 5));
	assert(printf("%d\n", -5) == ft_printf("%d\n", -5));
	assert(printf("%i\n", 5) == ft_printf("%i\n", 5));
	assert(printf("%i\n", -5) == ft_printf("%i\n", -5));
	assert(printf("%d\n", 0) == ft_printf("%d\n", 0));
	assert(printf("%d\n", 2147483647) == ft_printf("%d\n", 2147483647));

	assert(printf("%u\n", -65536) == ft_printf("%u\n", -65536));
	assert(printf("%u\n", 4294967295U) == ft_printf("%u\n", 4294967295U));

	assert(ft_printf("%x\n", 4294967295U) == printf("%x\n", 4294967295U));

	assert(ft_printf("%X\n", 4294967295U) == printf("%X\n", 4294967295U));

	assert(printf("%%\n") == ft_printf("%%\n"));

	assert(ft_printf("Multiple formats: %%, %i, %s\n", 42, "Hello, World!") == printf("Multiple formats: %%, %i, %s\n", 42, "Hello, World!"));

	printf("test % %\n");
	printf("% %\n");
	printf("test f % %\n");
	ft_printf("% %\n");
	return (0);
}