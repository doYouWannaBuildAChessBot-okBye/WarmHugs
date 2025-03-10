

// Do you wanna build a chessbot??????

#include <stdint.h>
#include <stdio.h>
#include <atohallan.h>

int
	main(
int argc,
char **argv
)
{
	uint64_t	numbie;
	uint64_t	count;

	printf("please enter a numbie\n");
	scanf("%zu", &numbie);
	asm("popcnt %1,%0" : "=r"(count) : "rm"(numbie) : "cc");
	printf("%zu popcnt %zu\n", numbie, count);
	printf("leave me alone anna!\n");
	return (1);
}
