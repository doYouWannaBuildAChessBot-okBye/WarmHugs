// Do you wanna build a chessbot??????

#include <stdint.h>
#include <stdio.h>
#include <atohallan.h>

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
		return (generic_popcnt(num));
	return (ret);
}

t_material
	count_material(
t_board board
)
{
	return ((t_material){
			.wK = popcount(board.wK),
			.bK = popcount(board.bK),
			.wQ = popcount(board.wQ),
			.bQ = popcount(board.bQ),
			.wB = popcount(board.wB),
			.bB = popcount(board.bB),
			.wN = popcount(board.wN),
			.bN = popcount(board.bN),
			.wR = popcount(board.wR),
			.bR = popcount(board.bR),
			.wP = popcount(board.wP),
			.bP = popcount(board.bP),
			});
}

int
	main(
int argc,
char **argv
)
{
	uint64_t	numbie;
	uint64_t	count;
	t_board		board;
	t_material	material;

	printf("please enter a numbie\n");
	numbie = 1ull << 63;
	asm("popcnt %1,%0" : "=r"(count) : "rm"(numbie) : "cc");
	printf("%zu popcnt %zu\n", numbie, count);
	board = START;
	material = count_material(board);
	printf("leave me alone anna!\n");
	return (0);
}
