#include <Windows.h>

module Renderer;

namespace Render {
	void setDisplayFunc( std::function<void()> fn )
	{
		displayFunc = fn;
	}

	void Display()
	{
		setCursorPos( { 0, 0 } );

		displayFunc();
	}

	void setCursorPos( Util::Coord pos )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {short(pos.x), short(pos.y)});
	}
}