#include <stdio.h>
#include "integer-input.h"

int main()
{
	puts("Enter integer:");
	int x;
	simpleInt(&x);
//	getIntegerFromStdin(&x);
	printf("You entered: %d\n", x);
//	int foo = getIntScanf(12);
//	printf("foo is %d\n", foo);
	return 0;
}
