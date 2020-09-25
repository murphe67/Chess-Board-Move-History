#pragma once
#include "piece.h"
#include "board.h"
#include "moveHistoryManager.h"
#include <iostream>
#include <map>

namespace chess
{
	/*Interface between board and pieces. All code to do with chess pieces passes through this object*/
	class pieceManager
	{
		public:

			#pragma region Public Methods

			/* This sets up the pieces with names and positions */
			void setBoard(board& GameBoard);

			/*Type in a piece name and co-ordinate to move piece to
			Calls _validateMoveInput for the piece and the square.
			Displays the board after a successful move.*/
			void MovePiece(std::string piece, std::string square);


			/*Type in a piece name and co-ordinate to move piece to
			Calls _validateCaptureInput for the piece and the square.
			Displays the board after a successful capture.*/
			void CapturePiece(std::string piece, std::string square);


			#pragma endregion 

			moveHistoryManager MyMoveHistoryManager;

		private:

			/*Pointer to the board variable in application*/
			board* _myBoard;

			#pragma region Private Methods


				#pragma region Reset Board


					/*Sets name and resets position of pawns */
					void _resetPawns();

					/*Sets name and resets position of rooks*/
					void _resetRooks();

					/*Sets name and resets position of bishops*/
					void _resetBishops();

					/*Sets name and resets position of knights*/
					void _resetKnights();

					/*Sets name and resets position of the king and queen*/
					void _resetKingAndQueen();


				#pragma endregion

				#pragma region Validate Move Input
				
					
					bool _validateMoveInput(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputGeneric(chess::piece* myPiece, chess::square* mySquare);

					void _StringCoordsToInt(std::string pieceCoords, std::string squareCoords, int pieceCoordsArray[2], int squareCoordsArray[2]);

					bool _validateMoveInputPawn(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputRook(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputKnight(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputBishop(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputQueen(chess::piece* myPiece, chess::square* mySquare);

					bool _validateMoveInputKing(chess::piece* myPiece, chess::square* mySquare);


				#pragma endregion

				#pragma region Validate Capture Input

					bool _validateCaptureInput(piece* myPiece, square* mySquare);

				#pragma endregion


			#pragma endregion

			#pragma region Chess Piece Variables

			chess::piece _whitePawns[8];
			chess::piece _blackPawns[8];
			chess::piece _whiteRooks[2];
			chess::piece _blackRooks[2];
			chess::piece _whiteBishops[2];
			chess::piece _blackBishops[2];
			chess::piece _whiteKnights[2];
			chess::piece _blackKnights[2];
			chess::piece _whiteQueen;
			chess::piece _blackQueen;
			chess::piece _whiteKing;
			chess::piece _blackKing;

			/*Map to get chess piece object from its name*/
			std::map<std::string, chess::piece*> chessPieceMap;

			#pragma endregion 

	};

}