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
typedef struct s_material t_material;
struct s_material
{
	char	wK;
	char	bK;
	char	wQ;
	char	bQ;
	char	wB;
	char	bB;
	char	wN;
	char	bN;
	char	wR;
	char	bR;
	char	wP;
	char	bP;
};

enum piece
{
	none,
	multiple,
	whiteKing,
	blackKing,
	whiteQueen,
	blackQueen,
	whiteBishop,
	blackBishop,
	whiteKnight,
	blackKnight,
	whiteRook,
	blackRook,
	whitePawn,
	blackPawn
};
struct position {
	t_board	board;
	int side_to_move;
	int castling_rights[2];
	int en_passant_square;
};
struct move {
	int from_square;
	int to_square;
	int promotion_type;
};
struct search_info {
	const struct position *pos;
	int time[2];
	int increment[2];
};

# define EMPTY ((uint64_t)0)
# define FULL ((uint64_t)-1)
# define WHITE 0
# define BLACK 1
# define WHITE_PCS(x) ((x).wK | (x).wQ | (x).wB | (x).wN | (x).wR | (x).wP)
# define BLACK_PCS(x) ((x).bK | (x).bQ | (x).bB | (x).bN | (x).bR | (x).bP)
# define ALL(x) (WHITE(x) | BLACK(x))
# define OPEN(x) (~(ALL(x)))
# define AFILE (0x0101010101010101LL)
# define BFILE (0x0202020202020202LL)
# define CFILE (0x0404040404040404LL)
# define DFILE (0x0808080808080808LL)
# define EFILE (0x1010101010101010LL)
# define FFILE (0x2020202020202020LL)
# define GFILE (0x4040404040404040LL)
# define HFILE (0x8080808080808080LL)
# define ROW1 (0xFFLL << 0 * 8)
# define ROW2 (0xFFLL << 1 * 8)
# define ROW3 (0xFFLL << 2 * 8)
# define ROW4 (0xFFLL << 3 * 8)
# define ROW5 (0xFFLL << 4 * 8)
# define ROW6 (0xFFLL << 5 * 8)
# define ROW7 (0xFFLL << 6 * 8)
# define ROW8 (0xFFLL << 7 * 8)
# define FILE(x) ((x) & 7)
# define RANK(x) ((x) / 8)
# define PAWN 0
# define KNIGHT 1
# define BISHOP 2
# define ROOK 3
# define QUEEN 4
# define KING 5
# define NO_TYPE 6
# define SUCCESS 0
# define FAILURE 1

# define START ((t_board){\
		.wK = EFILE & ROW1,\
		.bK = EFILE & ROW8,\
		.wQ = DFILE & ROW1,\
		.bQ = DFILE & ROW8, \
		.wB = (CFILE | FFILE) & ROW1,\
		.bB = (CFILE | FFILE) & ROW8,\
		.wN = (BFILE | GFILE) & ROW1,\
		.bN = (BFILE | GFILE) & ROW8,\
		.wR = (AFILE | HFILE) & ROW1,\
		.bR = (AFILE | HFILE) & ROW8,\
		.wP = ROW2, \
		.bP = ROW7 \
		})

unsigned int
	popcount(
		uint64_t num
		);
#endif
