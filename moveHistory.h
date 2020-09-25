#pragma once
#include "piece.h"
#include "square.h"

class moveHistory
{
	public:

		/*
		Constructor takes all the paramters required for the linked list. moveType = 'M' if moved, 'C' if captured
		*/
		moveHistory(chess::piece* myPiece, chess::square* mySquare, char moveType, moveHistory* previousMovePointer);

		/*
		Resets the history of the piece in the list above it and then deletes that object
		*/
		void ResetMoveHistory();
	
		/*
		Calls this function on the piece above it and then prints its own move
		*/
		void PrintMoveHistory();

		struct IncorrectMoveType : public std::exception
	{
		IncorrectMoveType(const char* what_arg)
		{
			IncorrectMoveType::what_arg = what_arg;
		};
		const char* what_arg;
		const char* what() const throw ()
		{
			return what_arg;
		}
	};

	private:

		std::string _moveString;
		moveHistory* _previousMovePointer;
};

