#include <iostream>
#include <map>

#include "Board.h"

constexpr auto BOARD_SIZE = 120;

void Board::newGame()
{

	c_piece start[120] = 
	{
		IV, IV, IV, IV, IV, IV, IV, IV, IV, IV,
		IV, IV, IV, IV, IV, IV, IV, IV, IV, IV,
		IV, WR, WN, WB, WQ, WK, WB, WN, WR, IV,
		IV, WP, WP, WP, WP, WP, WP, WP, WP, IV,
		IV, EM, EM, EM, EM, EM, EM, EM, EM, IV,
		IV, EM, EM, EM, EM, EM, EM, EM, EM, IV,
		IV, EM, EM, EM, EM, EM, EM, EM, EM, IV,
		IV, EM, EM, EM, EM, EM, EM, EM, EM, IV,
		IV, BP, BP, BP, BP, BP, BP, BP, BP, IV,
		IV, BR, BN, BB, BQ, BK, BB, BN, BR, IV,
		IV, IV, IV, IV, IV, IV, IV, IV, IV, IV,
		IV, IV, IV, IV, IV, IV, IV, IV, IV, IV 
	};
	
	m_board.reserve(BOARD_SIZE);

	for (int i = 0; i < BOARD_SIZE; i++)
		m_board.push_back(start[i]);

	//FENparser(startFEN);

}

void Board::FENparser(char* FENstring)
{
	//char startFEN[] = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

	std::map<char, c_piece> mymap = {
		{'r', BR},
		{'n', BK},
		{'b', BB},
		{'q', BQ},
		{'k', BK},
		{'p', BP},
		{'P', WP},
		{'R', WR},
		{'N', WK},
		{'B', WB},
		{'Q', WQ},
		{'K', WK}
	};

	int square;
	int rank = 7;
	int file = 0;

	for (int i = 0; FENstring[i] != ' '; i++)
	{
		if (FENstring[i] == '/')
		{
			rank--;
			file = 0;
		}
		else
		{
			if (isdigit(FENstring[i]))
				file += FENstring[i] - '0';
			else
			{
				square = rank * 8 + file;
				m_board[square] = mymap.find(FENstring[i])->second;
				file++;
			}
		}
	}
}

void Board::printBoard()
{
	int square;

	for (int rank = 0; rank < 12; rank++)
	{
		for (int file = 0; file < 10; file++)
		{
			square = rank * 10 + file;
			std::cout << m_board[square] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

bool Board::checkLegalMoves(squares start, squares end, c_piece piece)
{

	if (m_board[end] != EM)
		return false;

	switch (piece)
	{
		case WP:
			if (end == start + 10)
				return true;
			else if ((start >= A2 && start <= H2) && end == start + 20)
				return true;
			break;
		case BP:
			if ( end == start - 10 )
				return true;
			else if ((start >= A7 && start <= H7) && end == start - 20)
				return true;
			break;
	}
			
	return false;
}

void Board::move(squares start, squares end, c_piece piece)
{
	if (checkLegalMoves(start, end, piece))
	{
		c_piece temp = m_board[start];
		m_board[start] = m_board[end];
		m_board[end] = temp;
	}
	else
	{
		std::cout << "You cannot move there!" << std::endl << std::endl;
	}
	
}
