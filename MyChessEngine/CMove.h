#pragma once

#include "Board.h"

class CMove
{
	friend class Board;

public:
	CMove() {};

	void lMove(squares startpos, squares endpos, c_piece piece);

};

