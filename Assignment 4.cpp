#include "application.h"


int main() {
	try 
	{
		application myApp;
		myApp.Run();
	}
	catch (chess::piece::PieceEnumError & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Exiting program." << std::endl;
	}
	catch (chess::board::IncorrectCoord & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Exiting program." << std::endl;
	}
	catch (moveHistory::IncorrectMoveType & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Exiting program." << std::endl;
	}
}