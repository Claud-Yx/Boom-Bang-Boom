#include <Windows.h>

module Renderer;

import <format>;
import <iostream>;
import <string>;

namespace Render {

	void Render()
	{
		setCursorPos( { 0, 0 } );

		displayFunc();
	}

	void setCursorPos( Util::Coord pos )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { short( pos.x ), short( pos.y ) } );
	}

	void showCursor( bool show )
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		if ( !show ) {
			cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
			cursorInfo.bVisible = false; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è
		}
		else {
			cursorInfo.dwSize = 100; //Ä¿¼­ ±½±â (1 ~ 100)
			cursorInfo.bVisible = true; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è
		}
		SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &cursorInfo );
	}

	void setConsoleSize( unsigned short width, unsigned short height )
	{
		Render::width = width;
		Render::height = height;
		Util::width = width;
		Util::height = height;

		system( std::format( "mode con lines={} cols={}", height, width ).c_str() );
	}

	void setConsoleTitle( const char* title )
	{
		system( std::format( "title {}", title ).c_str() );
	}

	void clearConsole()
	{
		std::string blank{ std::format( "{0:<{1}}", "", width ) };
		for ( int y{}; y < height; ++y )
			std::cout << blank << std::endl;
	}
}