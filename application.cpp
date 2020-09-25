#include "application.h"
#include <iostream>
#include <string>
#include "pieceManager.h"

	#pragma region Public Methods

		/* The only public function in the chess application. Starts the chessboard program. */
		void application::Run()
	{
			std::cout << "Chess board: l " << std::endl;
			_newBoard();

			_displayCommands();
			_takeInput();

			while (_command != _commandsEnum(application::_commandsEnum::EXIT))
			{

				_executeCommand();
			}

			std::cout << "Exit command executed. Program shutting down.";
	}


	#pragma endregion 


	#pragma region Private Methods

			#pragma region Input

				/*Prompts the user for input, the calls _getCommandsEnum to store the input as an enumerator*/
				void application::_takeInput()
			{
				std::string command;
				std::cout << "Input command." << std::endl;

				getline(std::cin, command);
				_command = _getCommandsEnum(command);
			}

				/*Turns the command strings into command enumerator to allow switching*/
				application::_commandsEnum application::_getCommandsEnum(std::string command)
			{
				if (command == _newBoardCommand)
				{
					return _commandsEnum(application::_commandsEnum::NEW_BOARD);
				}
				else if (command == _displayBoardCoordsCommand)
				{
					return _commandsEnum(application::_commandsEnum::DISPLAY_COORDS);
				}
				else if (command == _displayPiecesCommand)
				{
					return _commandsEnum(application::_commandsEnum::DISPLAY_PIECES);
				}
				else if (command == _moveCommand)
				{
					return _commandsEnum(application::_commandsEnum::MOVE);
				}
				else if (command == _captureCommand)
				{
					return _commandsEnum(application::_commandsEnum::CAPTURE);
				}
				else if (command == _exitCommand)
				{
					return _commandsEnum(application::_commandsEnum::EXIT);
				}
				else if (command == _commandsCommand)
				{
					return _commandsEnum(application::_commandsEnum::COMMANDS);
				}
				else if (command == _resetMoveHistoryCommand)
				{
					return _commandsEnum(application::_commandsEnum::RESET_MOVE_HISTORY);
				}
				else if (command == _printMoveHistoryCommand)
				{
					return _commandsEnum(application::_commandsEnum::PRINT_MOVE_HISTORY);
				}
				else
				{
					return _commandsEnum(application::_commandsEnum::ERROR);
				}
			}

			#pragma endregion


			#pragma region User Commands


				/*Performs switch on command entered and redirects to correct command. 
				Also calls _takeInput automatically*/
				void application::_executeCommand()
			{
				switch (_command)
				{
				case application::_commandsEnum::NEW_BOARD:
					_newBoard();
					break;
				case application::_commandsEnum::DISPLAY_COORDS:
					_displayBoardCoordinates();
					break;
				case application::_commandsEnum::DISPLAY_PIECES:
					_displayPieces();
					break;
				case application::_commandsEnum::MOVE:
					_movePiece();
					break;
				case application::_commandsEnum::CAPTURE:
					_capturePiece();
					break;
				case application::_commandsEnum::EXIT:
					break;
				case application::_commandsEnum::COMMANDS:
					_displayCommands();
					break;
				case application::_commandsEnum::RESET_MOVE_HISTORY:
					_resetMoveHistory();
					break;
				case application::_commandsEnum::PRINT_MOVE_HISTORY:
					_printMoveHistory();
					break;
				case application::_commandsEnum::ERROR:
					break;
				}

				_takeInput();
			}


				/*Resets the board, then displays it*/
				void application::_newBoard()
				{
					myBoard.newBoard();
					myPieceManager.setBoard(myBoard);
					myBoard.DisplayPieces();
					myPieceManager.MyMoveHistoryManager.ResetMoveHistory();
				}

				/*Method called by _executeCommand for moving a piece.
				Takes input from user using cin, then passes it to the piece manager */
				void application::_movePiece()
				{
					std::string movingPiece;
					std::string squareCoOrds;

					std::cout << "Enter name of piece to be moved:" << std::endl;
					getline(std::cin, movingPiece);

					std::cout << "Enter co-ordinate to move to:" << std::endl;
					getline(std::cin, squareCoOrds);

					myPieceManager.MovePiece(movingPiece, squareCoOrds);
				}


				/*Method called by _executeCommand for capturing a piece.
				Takes input from user using cin, then passes it to the piece manager */
				void application::_capturePiece()
				{
					std::string movingPiece;
					std::string squareCoOrds;

					std::cout << "Enter name of piece to be moved:" << std::endl;
					getline(std::cin, movingPiece);

					std::cout << "Enter co-ordinate enemy piece is in:" << std::endl;
					getline(std::cin, squareCoOrds);

					myPieceManager.CapturePiece(movingPiece, squareCoOrds);
				}

				/*Display a grid of chess co-ordinates. Pieces aren't shown*/
				void application::_displayBoardCoordinates()
					{
						myBoard.PrintBoardCoordinates();
					}

				/*Display chess board with pieces on it*/
				void application::_displayPieces()
					{
						myBoard.DisplayPieces();
					}

				/*List all user commands to console*/
				void application::_displayCommands()
					{
						std::cout << "Commands available:" << std::endl << std::endl;
						std::cout << _newBoardCommand << " - Generates a new board." << std::endl;
						std::cout << _displayBoardCoordsCommand << " - Displays board coordinates" << std::endl;
						std::cout << _displayPiecesCommand << " - Displays pieces" << std::endl;
						std::cout << _moveCommand << " - Move a piece to a new location." << std::endl;
						std::cout << _captureCommand << " - Capture an opponent's piece." << std::endl;
						std::cout << _printMoveHistoryCommand << " - Print the move history." << std::endl;
						std::cout << _resetMoveHistoryCommand << " - Reset the move history." << std::endl;
						std::cout << _exitCommand << " - End the program" << std::endl;

						std::cout << _commandsCommand << " - List all available commands." << std::endl << std::endl;
					}

				void application::_resetMoveHistory()
				{
					myPieceManager.MyMoveHistoryManager.ResetMoveHistory();
				}

				void application::_printMoveHistory()
				{
					myPieceManager.MyMoveHistoryManager.PrintMoveHistory();
				}





			#pragma endregion

	#pragma endregion 