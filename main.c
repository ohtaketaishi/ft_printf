#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int n;

	n = ft_printf("%s\n", "kazunami");
	printf("%.p\n", &n);
//	n = printf("%.2147483647d", 21);
//	printf("%d\n", n);
	return (0);
}
