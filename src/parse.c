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
		}
	}

	return SUCCESS ;
}
