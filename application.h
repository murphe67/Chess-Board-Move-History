#pragma once
#include <iostream>
#include "board.h"
#include "pieceManager.h"

/*Chessboard Program*/
class application {

private:

		#pragma region Private Enumerators

			/* Enumerator for performing switches on user commands */
			enum class _commandsEnum
			{
				NEW_BOARD,
				DISPLAY_COORDS,
				DISPLAY_PIECES,
				MOVE,
				CAPTURE,
				EXIT,
				COMMANDS,
				RESET_MOVE_HISTORY,
				PRINT_MOVE_HISTORY,
				ERROR
			};

		#pragma endregion 


		#pragma region Private Methods	


			#pragma region Input

				/*Prompts the user for input, the calls _getCommandsEnum to store the input as an enumerator*/
				void _takeInput();
				
				/*Turns the command strings into command enumerator to allow switching*/
				_commandsEnum _getCommandsEnum(std::string command);

			#pragma endregion

			#pragma region User Commands

				/*Performs switch on command entered and redirects to correct command.
				Also calls _takeInput automatically*/
				void _executeCommand();

				/*Resets the board, then displays it*/
				void _newBoard();

				/*Method called by _executeCommand for moving a piece.
				Takes input from user using cin, then passes it to the piece manager */
				void _movePiece();

				/*Method called by _executeCommand for capturing a piece.
				Takes input from user using cin, then passes it to the piece manager */
				void _capturePiece();

				/*Display a grid of chess co-ordinates. Pieces aren't shown*/
				void _displayBoardCoordinates();

				/*Display chess board with pieces on it*/
				void _displayPieces();

				/*List all user commands to console*/
				void _displayCommands();

				void _resetMoveHistory();

				void _printMoveHistory();




			#pragma endregion
		

		#pragma endregion 


		#pragma region Command Variables

			/*the command the user entered as a string stored as an enumerator*/
			_commandsEnum _command;

			//These strings are printed to the console so the user knows what to input. 
			//Changing them here doesn't require a change anywhere else

			std::string _newBoardCommand = "/NewBoard";
			std::string _displayBoardCoordsCommand = "/DisplayCoords";
			std::string _displayPiecesCommand = "/DisplayPieces";
			std::string _moveCommand = "/Move";
			std::string _captureCommand = "/Capture";
			std::string _exitCommand = "/Exit";
			std::string _commandsCommand = "/Commands";
			std::string _resetMoveHistoryCommand = "/ResetMoveHistory";
			std::string _printMoveHistoryCommand = "/PrintMoveHistory";

		#pragma endregion


public:

		#pragma region Public Methods


			/* The only public function in the chess application. Starts the chessboard program. */
			void Run();


		#pragma endregion

		#pragma region Public Variables

			/*Reference to the board object*/
			chess::board myBoard;

			/*Reference to the piece manager object*/
			chess::pieceManager myPieceManager;


		#pragma endregion

};