#include "piece.h"

chess::piece::PieceTypeEnum chess::piece::getPieceType()
{
	{
		char charArray[4];
		strcpy_s(charArray, Name.c_str());

		switch (charArray[1])
		{
		case 'P':
			return piece::PieceTypeEnum::PAWN;
		case 'R':
			return piece::PieceTypeEnum::ROOK;
		case 'N':
			return piece::PieceTypeEnum::KNIGHT;
		case 'B':
			return piece::PieceTypeEnum::BISHOP;
		case 'K':
			return piece::PieceTypeEnum::KING;
		case 'Q':
			return piece::PieceTypeEnum::QUEEN;
		default:
			throw PieceEnumError("Error with type enumerator. This should never happen.");
		}
	}
}

chess::piece::PieceColorEnum chess::piece::getPieceColor()
{
	char charArray[4];
	strcpy_s(charArray, Name.c_str());

	switch (charArray[0])
	{
	case 'W':
		return piece::PieceColorEnum::WHITE;
	case 'B':
		return piece::PieceColorEnum::BLACK;
	default:
		throw PieceEnumError("Error with color enumerator. This should never happen.");
	}
}
