#include "board.h"
#include <iostream>
#include <string>  

		/*Resets the board*/
		void chess::board::newBoard()
		{
			for (int y = 8; y > 0; y--)
			{
				for (int x = 1; x < 9; x++)
				{
					chessSquareArray[x - 1][y - 1].Coords = IntCoordToCharCoord(x) + std::to_string(y);
					chessSquareArray[x - 1][y - 1].myPiece = 0;
				}
			}

		}

		#pragma region Display Methods

			/*Displays empty chess board with co-ordinates printed*/
			void chess::board::PrintBoardCoordinates()
			{
				for (int y = 8; y > 0; y--)
				{
					for (int x = 1; x < 9; x++)
					{
						std::cout << "|" << IntCoordToCharCoord(x) << y;
					}
					std::cout << "|" << std::endl;
				}
				std::cout << std::endl;
			}

			/*Display the chess board and piece locations*/
			void chess::board::DisplayPieces()
			{
				for (int y = 8; y > 0; y--)
				{
					for (int x = 1; x < 9; x++)
					{
						if (chessSquareArray[x - 1][y - 1].myPiece != 0)
						{
							std::cout << "|" << chessSquareArray[x - 1][y - 1].myPiece->Name;
						}
						else
						{
							std::cout << "|   ";
						}
					}
					std::cout << "|" << std::endl;
				}
				std::cout << std::endl;
			}


		#pragma endregion

		#pragma region Public Conversion Methods

			/*Converts x co-ordinate to letter*/
			char chess::board::IntCoordToCharCoord(int x)
		{
			switch (x)
			{
			case 1:
				return 'a';
			case 2:
				return 'b';
			case 3:
				return 'c';
			case 4:
				return 'd';
			case 5:
				return 'e';
			case 6:
				return 'f';
			case 7:
				return 'g';
			case 8:
				return 'h';
			default:
				throw IncorrectCoord("Exception: co-ordinate on board not valid.");
			}
		}
			/*Returns the square at that co-ordinate*/
			chess::square* chess::board::GetSquareFromCoord(std::string coord)
			{
				char charArray[3];
				strcpy_s(charArray, coord.c_str());

				int x = charArray[0] - 'a';
				int y = charArray[1] - '1';

				if (x > 7 || x < 0 || y > 7 || y < 0)
				{
					return 0;
				}
				return &chessSquareArray[x][y];
			}


		#pragma endregion