#pragma once
#include <iostream>
#include "piece.h"

namespace chess
{
	/*Chess square. Stores co-ords and piece only. No methods*/
	class square {
	public:
		/*String storing square co-ordinates*/
		std::string Coords;

		/*Pointer to a piece object if the square is occupied*/
		chess::piece* myPiece = 0;
	};
}