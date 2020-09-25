#pragma once
#include <string>

namespace chess
{
	/*Class to represent a chess piece. Has variable for name, position, coords, moves taken and whether has been captured
	Has properties for type and color based on variables*/
	class piece {
		
	public:

		#pragma region Public Enum

			enum class PieceTypeEnum
			{
				PAWN,
				ROOK,
				BISHOP,
				KNIGHT,
				QUEEN,
				KING
			};

			enum class PieceColorEnum
			{
				BLACK,
				WHITE
			};

		#pragma endregion


		struct PieceEnumError : public std::exception
		{
			PieceEnumError(const char* what_arg)
			{
				PieceEnumError::what_arg = what_arg;
			};
			const char* what_arg;
			const char* what() const throw ()
			{
				return what_arg;
			}
		};
	
		/* The location of this chess piece as a string */
		std::string Coords;

		/* The name of this chess piece */
		std::string Name;
		
		/*How many times a piece has moved this game*/
		int MovesTaken;

		bool Captured = false;

		/*Get the piece type as an enumerator*/
		piece::PieceTypeEnum getPieceType();

		piece::PieceColorEnum getPieceColor();

	};
}