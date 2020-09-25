#include "moveHistoryManager.h"

void moveHistoryManager::AddToMoveHistory(chess::piece* myPiece, chess::square* mySquare, char moveType)
{
	moveHistory* currentMove = new moveHistory(myPiece, mySquare, moveType, lastMove);
	lastMove = currentMove;
}

void moveHistoryManager::ResetMoveHistory()
{
	if (lastMove != 0)
	{
		lastMove->ResetMoveHistory();

		delete lastMove;
		lastMove = 0;
		std::cout << "Move History Reset" << std::endl;
	}
	else 
	{
		std::cout << "No history to reset" << std::endl;
	}
}

void moveHistoryManager::PrintMoveHistory()
{
	if (lastMove != 0)
	{
		lastMove->PrintMoveHistory();
	}
	else
	{
		std::cout << "No moves taken" << std::endl;
	}
}
