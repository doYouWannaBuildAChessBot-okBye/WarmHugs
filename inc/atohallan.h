#ifndef ATOHALLAN_H
# define ATOHALLAN_H
#include <stdint.h>

typedef struct s_chessboard t_board;
struct s_chessboard
{
	uint64_t	wK;
	uint64_t	bK;
	uint64_t	wQ;
	uint64_t	bQ;
	uint64_t	wB;
	uint64_t	bB;
	uint64_t	wN;
	uint64_t	bN;
	uint64_t	wR;
	uint64_t	bR;
	uint64_t	wP;
	uint64_t	bP;
};

#define EMPTY ((uint64_t)0)
#define FULL ((uint64_t)-1)
#define WHITE(x) ((x).wK | (x).wQ | (x).wB | (x).wN | (x).wR | (x).wP)
#define BLACK(x) ((x).bK | (x).bQ | (x).bB | (x).bN | (x).bR | (x).bP)
#define ALL(x) (WHITE(x) | BLACK(x))
#define OPEN(x) (~(ALL(x)))

#endif
