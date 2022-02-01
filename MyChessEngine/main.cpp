#include "Board.h"

int main()
{
	Board myBoard;

	myBoard.printBoard();
	myBoard.move(D2, D4, WP);
	myBoard.printBoard();

	return 0;
}