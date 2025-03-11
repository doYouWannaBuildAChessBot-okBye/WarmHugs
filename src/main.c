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
	{
		dprintf(2, "using generic popcount\n");
		return (generic_popcnt(num));
	}
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

void
	print_board(
t_board board
)
{
	char		representation[64];
	enum piece	current;

	for (unsigned int i = 0; i < 64; i++)
	{
		uint64_t	mask = 1ull << i;

		if (board.wK & mask)
			representation[i] = 'k';
		else if (board.bK & mask)
			representation[i] = 'K';
		else if (board.wQ & mask)
			representation[i] = 'q';
		else if (board.bQ & mask)
			representation[i] = 'Q';
		else if (board.wB & mask)
			representation[i] = 'b';
		else if (board.bB & mask)
			representation[i] = 'B';
		else if (board.wN & mask)
			representation[i] = 'n';
		else if (board.bN & mask)
			representation[i] = 'N';
		else if (board.wR & mask)
			representation[i] = 'r';
		else if (board.bR & mask)
			representation[i] = 'R';
		else if (board.wP & mask)
			representation[i] = 'p';
		else if (board.bP & mask)
			representation[i] = 'P';
		else
			representation[i] = '.';
	}
	printf("%.8s\n", &representation[56]);
	printf("%.8s\n", &representation[48]);
	printf("%.8s\n", &representation[40]);
	printf("%.8s\n", &representation[32]);
	printf("%.8s\n", &representation[24]);
	printf("%.8s\n", &representation[16]);
	printf("%.8s\n", &representation[8]);
	printf("%.8s\n", &representation[0]);
}

void
	print_state(
t_board board
)
{
	printf("wK %zx\nbK %zx\nwQ %zx\nbQ %zx\nwB %zx\nbB %zx\nwN %zx\nbN %zx\nwR %zx\nbR %zx\nwP %zx\nbP %zx\n",
			board.wK, board.bK, board.wQ, board.bQ, board.wB, board.bB, board.wN, board.bN, board.wR, board.bR,
			board.wP, board.bP);
}

int
	main(
int argc,
char **argv
)
{
	t_board		board;
	t_material	material;

	board = START;
	material = count_material(board);
	printf("leave me alone anna!\n");
	print_board(board);
	/*print_state(board);*/
	return (0);
}
