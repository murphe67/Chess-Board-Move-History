#pragma once
#include "moveHistory.h"

class moveHistoryManager
{
	private:

		moveHistory* lastMove = 0;

	public:
		
		void AddToMoveHistory(chess::piece* myPiece, chess::square* mySquare, char moveType);
		
		void ResetMoveHistory();

		void PrintMoveHistory();



};

