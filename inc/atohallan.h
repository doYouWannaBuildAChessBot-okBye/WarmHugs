#ifndef ATOHALLAN_H
# define ATOHALLAN_H
#include <stdint.h>

typedef struct s_chessboard t_board;
struct s_chessboard
{
	uint64_t	whiteKings;
	uint64_t	blackKings;
	uint64_t	whiteQueens;
	uint64_t	blackQueens;
	uint64_t	whiteBishops;
	uint64_t	blackBishops;
	uint64_t	whiteKnights;
	uint64_t	blackKnights;
	uint64_t	whiteRooks;
	uint64_t	blackRooks;
	uint64_t	whitePawns;
	uint64_t	blackPawns;
};

#define EMPTY ((uint64_t)0)
#define FULL ((uint64_t)-1)

#endif
