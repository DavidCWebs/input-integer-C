#include <stdio.h>
#include "integer-input.h"

int main()
{
	int x, y, z;

	puts("simpleInt() enter integer:");
	simpleInt(&x);
	printf("You entered: %d\n", x);

	puts("getIntegerFromStdin() enter integer:");
	getIntegerFromStdin(&y);
	printf("You entered: %d\n", y);
	
	
	z = getIntScanf(12);
	printf("You entered: %d\n", z);
	return 0;
}
