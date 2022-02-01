#include "Board.h"

int main()
{
	Board myBoard;

	myBoard.printBoard();
	myBoard.move(G1, F3, WN);
	myBoard.printBoard();

	return 0;
}