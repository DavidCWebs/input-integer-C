#include <stdio.h>
#include "integer-input.h"

int main()
{
	puts("Enter integer:");
	int x;
	getIntegerFromStdin(&x);
	printf("You entered: %d\n", x);
	return 0;
}
