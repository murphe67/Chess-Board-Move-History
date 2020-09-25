#pragma once
#include "square.h"
#include <iostream>

namespace chess {

	/*Chess board. Can print out the board, deals with co-ord conversions and retrieving specific squares*/
	class board {
		public:

			#pragma region Public Methods


				/*Displays empty chess board with co-ordinates printed*/
				void PrintBoardCoordinates();

				/*Display the chess board and piece locations*/
				void DisplayPieces();

				/*Resets the board*/
				void newBoard();

				/*Converts x co-ordinate to letter*/
				char IntCoordToCharCoord(int x);

				/*Returns the square at that co-ordinate*/
				square* GetSquareFromCoord(std::string coord);


			#pragma endregion	


			#pragma region Public Variables
	
				/*Array storing chess squares*/
				chess::square chessSquareArray[8][8];


			#pragma endregion


			struct IncorrectCoord : public std::exception
			{
				IncorrectCoord(const char* what_arg)
				{
					IncorrectCoord::what_arg = what_arg;
				};
				const char* what_arg;
				const char* what() const throw ()
				{
					return what_arg;
				}
			};
	
	};

}