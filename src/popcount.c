#include <stdio.h>
#include <stdint.h>

unsigned int
	generic_popcnt(
uint64_t num
)
{
	unsigned int ret;

	for (int i = 0; i < 64; i++)
		if ((num >> i) & 1)
			ret++;
	return (ret);
}

unsigned int
	popcount(
uint64_t num
)
{
	uint64_t	ret;

	if (__builtin_cpu_supports("popcnt"))
		asm("popcnt %1,%0" : "=r"(ret) : "rm"(num) : "cc");
	else
	{
		dprintf(2, "using generic popcount\n");
		return (generic_popcnt(num));
	}
	return (ret);
}

