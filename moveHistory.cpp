#pragma once
#include "moveHistory.h"


moveHistory::moveHistory(chess::piece* myPiece, chess::square* mySquare, char moveType, moveHistory* previousMovePointer)
{

	switch (moveType)
	{
		case 'M': 	
			_moveString = myPiece->Name + " moved to square " + mySquare->Coords;
			break;
		case 'C':
			_moveString = myPiece->Name + " moved to square " + mySquare->Coords + ", capturing " + mySquare->myPiece->Name;
			break;
		default:
			throw IncorrectMoveType("Move type passed incorrectly. This should never happen");
	}

	_previousMovePointer = previousMovePointer;
}

void moveHistory::ResetMoveHistory()
{
	if (_previousMovePointer != 0)
	{
		_previousMovePointer->ResetMoveHistory();
	}

	delete _previousMovePointer;
	_previousMovePointer = 0;
}

void moveHistory::PrintMoveHistory()
{
	if (_previousMovePointer != 0)
	{
		_previousMovePointer->PrintMoveHistory();
	}

	std::cout << _moveString << std::endl;
}
