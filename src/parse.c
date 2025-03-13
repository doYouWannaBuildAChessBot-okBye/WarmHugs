#include <atohallan.h>
#include <ctype.h>

int
	parse_position(
struct position *pos,
const char *fen
)
{
	t_board board = {0};
	int		position = 0;

	while (position < 64)
	{
		if (*fen == '/')
			fen++;
		if (isdigit(*fen)) {
			position += *fen++ - '0';
			continue ;
		}
		if (*fen == 'p') {
			board.bP += 1ll << (63 - (63 - position));
			fen++;
		} else if (*fen == 'P') {
			board.wP += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'r') {
			board.bR += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'R') {
			board.wR += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'n') {
			board.bN += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'N') {
			board.wN += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'b') {
			board.bB += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'B') {
			board.wB += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'q') {
			board.bQ += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'Q') {
			board.wQ += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'k') {
			board.bK += 1ll << (63 - position);
			fen++;
		} else if (*fen == 'K') {
			board.wK += 1ll << (63 - position);
			fen++;
		} else {
			return (FAILURE);
		}
	}
	if (*fen++ != ' ')
		return (FAILURE);
	if (*fen == 'w') {
		pos->side_to_move = WHITE;
	} else if (*fen == 'b') {
		pos->side_to_move = BLACK;
	} else
		return (FAILURE);
	fen++;
	if (*fen++ != ' ')
		return (FAILURE);
	if (*fen == '-')
		fen++;
	else
	{
		const char *start  = fen;
		if (*fen == 'K') {
			pos->castling_rights[WHITE] |= KING_SIDE;
			fen++;
		}
		if (*fen == 'Q') {
			pos->castling_rights[WHITE] |= QUEEN_SIDE;
			fen++;
		}
		if (*fen == 'k') {
			pos->castling_rights[BLACK] |= KING_SIDE;
			fen++;
		}
		if (*fen == 'q') {
			pos->castling_rights[BLACK] |= QUEEN_SIDE;
			fen++;
		}
		if (fen == start)
			return (FAILURE);
	}
	if (*fen++ != ' ')
		return (FAILURE);
	pos->en_passant_square = parse_en_passant(fen);
	if (pos->en_passant_square != NO_SQUARE) {
		fen += 2;
	} else if (*fen == '-') {
		fen++;
	} else
		return (FAILURE);
	for (int index = 0; index < 2; index++)
	{
		if (*fen++ != ' ')
			return (FAILURE);
		if (*fen < '0' || *fen > '9')
			return (FAILURE);
		while (*fen >= '0' && *fen <= '9')
			fen++;
	}
	if (*fen)
		return (FAILURE);
	return (SUCCESS);
}
