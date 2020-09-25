#include "pieceManager.h"
#include <iostream>

		#pragma region Reset Board

		void chess::pieceManager::setBoard(board& myBoard)
		{
			_myBoard = &myBoard;

			_resetPawns();
			_resetRooks();
			_resetKnights();
			_resetBishops();
			_resetKingAndQueen();

			//iterate through the map of pieces and set them to uncaptured
			for (std::map<std::string, chess::piece*>::iterator it = chessPieceMap.begin(); it != chessPieceMap.end(); ++it)
			{
				it->second->Captured = false;
			}
		}

		//pawn is the only one of these commented but theyre all identical
		void chess::pieceManager::_resetPawns()
		{
			for (int i = 0; i < 8; i++)
			{
				_whitePawns->MovesTaken = 0;

				//set names
				_whitePawns[i].Name = "WP" + std::to_string(i + 1);
				_blackPawns[i].Name = "BP" + std::to_string(i + 1);

				//store in the map
				chessPieceMap[_whitePawns[i].Name] = &(_whitePawns[i]);
				chessPieceMap[_blackPawns[i].Name] = &(_blackPawns[i]);

				//set coords
				_whitePawns[i].Coords = _myBoard->IntCoordToCharCoord(i + 1) + std::to_string(2);
				_blackPawns[i].Coords = _myBoard->IntCoordToCharCoord(i + 1) + std::to_string(7);

				//assign to square
				_myBoard->chessSquareArray[i][1].myPiece = &_whitePawns[i];
				_myBoard->chessSquareArray[i][6].myPiece = &_blackPawns[i];
			}
		}

		void chess::pieceManager::_resetRooks()
		{
			for (int i = 0; i < 2; i++)
			{
				_whiteRooks[i].Name = "WR" + std::to_string(i + 1);
				_blackRooks[i].Name = "BR" + std::to_string(i + 1);

				chessPieceMap[_whiteRooks[i].Name] = &(_whiteRooks[i]);
				chessPieceMap[_blackRooks[i].Name] = &(_blackRooks[i]);

				//setting the x location of the piece
				int x = 1;
				if (i != 0)
				{
					x = 8;
				}

				//store the location in the piece
				_whiteRooks[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(1);
				_blackRooks[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(8);

				//store the piece in the square
				(*_myBoard).chessSquareArray[x-1][0].myPiece = &_whiteRooks[i];
				(*_myBoard).chessSquareArray[x-1][7].myPiece = &_blackRooks[i];
			}
		}

		void chess::pieceManager::_resetKnights()
		{
			for (int i = 0; i < 2; i++)
			{
				_whiteKnights[i].Name = "WN" + std::to_string(i + 1);
				_blackKnights[i].Name = "BN" + std::to_string(i + 1);

				chessPieceMap[_whiteKnights[i].Name] = &(_whiteKnights[i]);
				chessPieceMap[_blackKnights[i].Name] = &(_blackKnights[i]);

				//setting the x location of the piece
				int x = 2;
				if (i != 0)
				{
					x = 7;
				}

				//store the location in the piece
				_whiteKnights[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(1);
				_blackKnights[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(8);

				//store the piece in the square
				(*_myBoard).chessSquareArray[x - 1][0].myPiece = &_whiteKnights[i];
				(*_myBoard).chessSquareArray[x - 1][7].myPiece = &_blackKnights[i];
		
			}
		}

		void chess::pieceManager::_resetBishops()
		{
			for (int i = 0; i < 2; i++)
			{
				_whiteBishops[i].Name = "WB" + std::to_string(i + 1);
				_blackBishops[i].Name = "BB" + std::to_string(i + 1);

				chessPieceMap[_whiteBishops[i].Name] = &(_whiteBishops[i]);
				chessPieceMap[_blackBishops[i].Name] = &(_blackBishops[i]);

				//setting the x location of the piece
				int x = 3;
				if (i != 0)
				{
					x = 6;
				}

				//store the location in the piece
				_whiteBishops[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(1);
				_blackBishops[i].Coords = (*_myBoard).IntCoordToCharCoord(x) + std::to_string(8);

				//store the piece in the square
				(*_myBoard).chessSquareArray[x - 1][0].myPiece = &_whiteBishops[i];
				(*_myBoard).chessSquareArray[x - 1][7].myPiece = &_blackBishops[i];

			}
		}

		void chess::pieceManager::_resetKingAndQueen()
		{
				_whiteKing.Name = "WK1";
				_blackKing.Name = "BK1";

				_whiteQueen.Name = "WQ1";
				_blackQueen.Name = "BQ1";

				chessPieceMap[_whiteKing.Name] = &(_whiteKing);
				chessPieceMap[_blackKing.Name] = &(_blackKing);
				chessPieceMap[_whiteQueen.Name] = &(_whiteQueen);
				chessPieceMap[_blackQueen.Name] = &(_blackQueen);

				//store the location in the piece
				_whiteKing.Coords = (*_myBoard).IntCoordToCharCoord(4) + std::to_string(1);
				_blackKing.Coords = (*_myBoard).IntCoordToCharCoord(4) + std::to_string(8);

				_whiteQueen.Coords = (*_myBoard).IntCoordToCharCoord(5) + std::to_string(1);
				_blackQueen.Coords = (*_myBoard).IntCoordToCharCoord(5) + std::to_string(8);

				//store the piece in the square
				(*_myBoard).chessSquareArray[3][0].myPiece = &_whiteKing;
				(*_myBoard).chessSquareArray[3][7].myPiece = &_blackKing;

				(*_myBoard).chessSquareArray[4][0].myPiece = &_whiteQueen;
				(*_myBoard).chessSquareArray[4][7].myPiece = &_blackQueen;
	
		}

		#pragma endregion

		#pragma region Move Pieces

			/*Type in a piece name and co-ordinate to move piece to
			Calls _validateMoveInput for the piece and the square.
			Displays the board after a successful move.*/
			void chess::pieceManager::MovePiece(std::string pieceString, std::string squareString)
		{
			chess::piece* myPiece;
			myPiece = chessPieceMap[pieceString];

			chess::square* mySquare = _myBoard->GetSquareFromCoord(squareString);

			if (!_validateMoveInput(myPiece, mySquare))
			{
				return;
			}

			MyMoveHistoryManager.AddToMoveHistory(myPiece, mySquare, 'M');

			(*_myBoard).GetSquareFromCoord(myPiece->Coords)->myPiece = 0;

			mySquare->myPiece = myPiece;

			myPiece->Coords = squareString;
			myPiece->MovesTaken++;

			std::cout << std::endl;
			_myBoard->DisplayPieces();
			
		}

			/*Type in a piece name and co-ordinate to move piece to
			Calls _validateCaptureInput for the piece and the square.
			Displays the board after a successful capture.*/
			void chess::pieceManager::CapturePiece(std::string pieceString, std::string squareString)
			{
				chess::piece* myPiece;
				myPiece = chessPieceMap[pieceString];

				chess::square* mySquare = _myBoard->GetSquareFromCoord(squareString);

				if (!_validateCaptureInput(myPiece, mySquare))
				{
					return;
				}

				MyMoveHistoryManager.AddToMoveHistory(myPiece, mySquare, 'C');

				(*_myBoard).GetSquareFromCoord(myPiece->Coords)->myPiece = 0;

				mySquare->myPiece->Captured = true;
				mySquare->myPiece = myPiece;

				myPiece->Coords = squareString;
				myPiece->MovesTaken++;

				std::cout << std::endl;
				_myBoard->DisplayPieces();

			}

			#pragma region Validate Move


				/*General function called by movePiece. 
				Does all general checking then delegates to specific function*/
				bool chess::pieceManager::_validateMoveInput(piece* myPiece, square* mySquare)
				{
					if (mySquare == 0)
					{
						std::cout << "Square co-ordinate entered incorrectly" << std::endl;
						return false;
					}
					else if (mySquare->myPiece != 0)
					{
						std::cout << "Square co-ordinate occupied" << std::endl;
						return false;
					}

					return _validateMoveInputGeneric(myPiece, mySquare);
				}

				bool chess::pieceManager::_validateMoveInputGeneric(chess::piece* myPiece, chess::square* mySquare)
				{
					if (myPiece == 0)
					{
						std::cout << "Piece name entered incorrectly" << std::endl;
						return false;
					}
					if (myPiece->Captured)
					{
						std::cout << "Piece no longer on the board" << std::endl;
						return false;
					}
					else
					{
						switch (myPiece->getPieceType())
						{
						case piece::PieceTypeEnum::PAWN:
							return _validateMoveInputPawn(myPiece, mySquare);
						case piece::PieceTypeEnum::ROOK:
							return _validateMoveInputRook(myPiece, mySquare);
						case piece::PieceTypeEnum::KNIGHT:
							return _validateMoveInputKnight(myPiece, mySquare);
						case piece::PieceTypeEnum::BISHOP:
							return _validateMoveInputBishop(myPiece, mySquare);
						case piece::PieceTypeEnum::KING:
							return _validateMoveInputKing(myPiece, mySquare);
						case piece::PieceTypeEnum::QUEEN:
							return _validateMoveInputQueen(myPiece, mySquare);
						default:
							return true;
						}
					}
				}
				

				/*Takes the coord strings and returns an integer 0 based array.
				[0] is the x coords, [1] is the y coords*/
				void chess::pieceManager::_StringCoordsToInt(std::string pieceCoords, std::string squareCoords, int pieceCoordsArray[2], int squareCoordsArray[2])
				{
					char pieceArray[3];
					strcpy_s(pieceArray, pieceCoords.c_str());
					pieceCoordsArray[0] = pieceArray[0] - 'a';
					pieceCoordsArray[1] = pieceArray[1] - '0';

					char squareArray[3];
					strcpy_s(squareArray, squareCoords.c_str());
					squareCoordsArray[0] = squareArray[0] - 'a';
					squareCoordsArray[1] = squareArray[1] - '0';
				}

				bool chess::pieceManager::_validateMoveInputPawn(piece* myPiece, square* mySquare)
				{
					//Set direction pawn goes based on color
					int direction = 1;
					if (myPiece->getPieceColor() == piece::PieceColorEnum::BLACK)
					{
						direction = -1;
					}

					//arrays to store coords for easy comparison
					int pieceCoords[2], squareCoords[2];
			
					//store the coords in the arrays from the strings
					_StringCoordsToInt(myPiece->Coords, mySquare->Coords, pieceCoords, squareCoords);

					if (pieceCoords[0] != squareCoords[0])
					{
						std::cout << "Pawn cannot move to that square." << std::endl;
						return false;
					}
					else if ((pieceCoords[1]) + 1 * direction == squareCoords[1])
					{
						return true;
					}
					else if ((pieceCoords[1] + 2 * direction) == squareCoords[1] && myPiece->MovesTaken == 0)
					{
						return true;
					}
					else
					{
						std::cout << "Pawn cannot move to that square." << std::endl;
						return false;
					}

				}

				bool chess::pieceManager::_validateMoveInputRook(chess::piece* myPiece, chess::square* mySquare)
				{
					//arrays to store coords for easy comparison
					int pieceCoords[2], squareCoords[2];

					//store the coords in the arrays from the strings
					_StringCoordsToInt(myPiece->Coords, mySquare->Coords, pieceCoords, squareCoords);

					if (pieceCoords[0] == squareCoords[0])
					{
						return true;
					}
					else if (pieceCoords[1] == squareCoords[1])
					{
						return true;
					}
					else
					{
						std::cout << "Rook cannot move to that square." << std::endl;
						return false;
					}

				}

				bool chess::pieceManager::_validateMoveInputKnight(chess::piece* myPiece, chess::square* mySquare)
				{
					//arrays to store coords for easy comparison
					int pieceCoords[2], squareCoords[2];

					//store the coords in the arrays from the strings
					_StringCoordsToInt(myPiece->Coords, mySquare->Coords, pieceCoords, squareCoords);

					if (pieceCoords[0] + 1 == squareCoords[0] || pieceCoords[0] - 1 == squareCoords[1])
					{
						if (pieceCoords[1] + 2 == squareCoords[1] || pieceCoords[1] - 2 == squareCoords[1])
						{
							return true;
						}
					}
					else if (pieceCoords[0] + 2 == squareCoords[0] || pieceCoords[0] - 2 == squareCoords[1])
					{
						if (pieceCoords[1] + 1 == squareCoords[1] || pieceCoords[1] - 1 == squareCoords[1])
						{
							return true;
						}
					}

					std::cout << "Knight cannot move to that square." << std::endl;
					return false;

				}

				bool chess::pieceManager::_validateMoveInputBishop(chess::piece* myPiece, chess::square* mySquare)
				{
					//arrays to store coords for easy comparison
					int pieceCoords[2], squareCoords[2];

					//store the coords in the arrays from the strings
					_StringCoordsToInt(myPiece->Coords, mySquare->Coords, pieceCoords, squareCoords);

					if (abs(pieceCoords[0] - squareCoords[0]) == abs(pieceCoords[1] - squareCoords[1]))
					{
						return true;
					}
					std::cout << "Bishop cannot move to that square." << std::endl;
					return false;
				}

				bool chess::pieceManager::_validateMoveInputQueen(chess::piece* myPiece, chess::square* mySquare)
				{
					if (_validateMoveInputRook(myPiece, mySquare) || _validateMoveInputBishop(myPiece, mySquare))
					{
						return true;
					}
					std::cout << "Queen cannot move to that square." << std::endl;
						return false;
				}

				bool chess::pieceManager::_validateMoveInputKing(chess::piece* myPiece, chess::square* mySquare)
				{
					//arrays to store coords for easy comparison
					int pieceCoords[2], squareCoords[2];

					//store the coords in the arrays from the strings
					_StringCoordsToInt(myPiece->Coords, mySquare->Coords, pieceCoords, squareCoords);

					if (abs(pieceCoords[0] - squareCoords[0]) == 1 && abs(pieceCoords[1] - squareCoords[1]) == 1)
					{
						return true;
					}
					if (abs(pieceCoords[0] - squareCoords[0]) + abs(pieceCoords[1] - squareCoords[1]) == 1)
					{
						return true;
					}
					std::cout << "King cannot move to that square." << std::endl;
					return false;
				}





		#pragma endregion

		#pragma endregion

		#pragma region Capture Piece

							bool chess::pieceManager::_validateCaptureInput(piece* myPiece, square* mySquare)
							{
								if (mySquare == 0)
								{
									std::cout << "Square co-ordinate entered incorrectly" << std::endl;
									return false;
								}
								else if (mySquare->myPiece == 0)
								{
									std::cout << "Square co-ordinate not occupied" << std::endl;
									return false;
								}
								else if (myPiece->getPieceColor() == mySquare->myPiece->getPieceColor())
								{
									std::cout << "Cannot capture a piece of the same color" << std::endl;
									return false;
								}

								return _validateMoveInputGeneric(myPiece, mySquare);
							}


			#pragma endregion